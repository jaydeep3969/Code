#include <bits/stdc++.h>
using namespace std;

enum color {RED, BLACK};

/*
    For Graphical Visualization :- https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
*/

struct Node {
    int key;
    bool color;
    Node *l, *r, *parent;
    Node (int k) 
    { 
        key = k; 
        color = RED;
        l = r = parent = NULL; 
    } 
} *root;

/*  --- LEFT ROTATE ---
    Steps:
    pt = new -> GrandParent, root
        x              y
       / \            / \
      #   y    =>    x   new
         / \        / \
        T2 new     #   T2
    #G4G {
    x = GrandParent --> Pt
    y = Parent --> PtR (Pt -> r)
    T2 --> PtRL (PtR -> L) }

    1. Connect X to T2 (x -> r = T2)
    2. Connect T2 to X (T2 -> parent = X)
    3. Connect Y to X's Parent (Y -> Parent = X -> Parent)
    4. If X's parent is NULL (X is root) then make Y as root (root = Y)
    5. If X's parent is notNULL (X is not root) then connect that Parent(PP) to Y
       --> If X is left child of PP then make PP -> l = Y
       --> If X is right child of PP then make PP -> r = Y
    6. Connect Y to X in both direction (Y -> l = X, X -> parent = Y)

    (1, 2) : Handling (X-T2) Connection
    (3, 4, 5) : Handling (Parent of X - Y) Connection
    (6) : Handling (x-Y) Connection
*/
void leftRotate(Node *x) {
    /* Right-Right Case
        x              y
       / \            / \
      #   y    =>    x   new
         / \        / \
        T2 new     #   T2
    */

    /* Left-Right Case
            P              P
           /              /
          x              y
         / \     =>     / \
        #   y          x  new
           / \        / \
          T2 new     #  T2
    */

    /* No Changes in # and new */

   Node *y = x -> r;
   Node *T2 = y -> l;

    x -> l = T2; // 1

    if(T2)
        T2 -> parent = x; // 2
    
    y -> parent = x -> parent; // 3

    if(!x -> parent)
        root = y; // 4
    else if (x == x -> parent -> l)
        x -> parent -> l = y; // 5
    else
        x -> parent -> r = y; // 5

    // 6
    y -> r = x;
    x -> parent = y;
}

/*  --- RIGHT ROTATE ---
    Steps:
    pt = new -> GrandParent, root
           x            y
          / \          / \
         y   #  =>   new  x
        / \              / \
      new  T2           T2  #
    #G4G {
    x = GrandParent --> Pt
    y = Parent --> PtL (Pt -> l)
    T2 --> PtLR (PtL -> R) }

    1. Connect X to T2 (x -> l = T2)
    2. Connect T2 to X (T2 -> parent = X)
    3. Connect Y to X's Parent (Y -> Parent = X -> Parent)
    4. If X's parent is NULL (X is root) then make Y as root (root = Y)
    5. If X's parent is notNULL (X is not root) then connect that Parent(PP) to Y
       --> If X is left child of PP then make PP -> l = Y
       --> If X is right child of PP then make PP -> r = Y
    6. Connect Y to X in both direction (Y -> r = X, X -> parent = Y)
*/
void rightRotate(Node *x) {
    /* Left-Left Case
           x            y
          / \          / \
         y   #  =>   new  x
        / \              / \
      new  T2           T2  #
    */

    /* Right-Left Case
        P              P
         \              \
          x              y
         / \   =>       / \
        y   #         new  x
       / \                / \
     new  T2             T2   #
    */

    /* No Changes in # and new */

    Node *y = x -> l;
    Node *T2 = y -> r;

    x -> l = T2; // 1

    if(T2)
        T2 -> parent = x; // 2

    y -> parent = x -> parent; // 3

    if(!x -> parent)
        root = y; // 4
    else if (x == x -> parent -> l)
        x -> parent -> l = y; // 5
    else
        x -> parent -> r = y; // 5

    y -> r = x;
    x -> parent = y;
}

Node* findInorderSuccessor(Node *n) {
    if(!n || !n->r) return NULL;
    
    n = n->r;
    while(n->l)
        n = n->l;

    return n;
}


/*
    Inserts newly created node (n) in BST
*/
Node* insertBST(Node *root, Node *n) {
    if(!root) return n;

    if(root -> key > n -> key)  {
        root -> l = insertBST(root -> l, n);
        root -> l -> parent = root;
    } else if(root -> key < n -> key) {
        root -> r = insertBST(root -> r, n);
        root -> r -> parent = root;
    }

    return root;
}


/*  --- BALANCING RB TREE ---
Two types of actions are possible :
1. Recoloring
2. Rotations

-- If Uncle is RED 
    -- Recoloring
-- If Uncle is NULL || Uncle is Black 
    -- Rotations
-- Repeat upto R0
-- Make R0 BLACK

- N = new Node, GP = GrandParent, P = Parent
- Color(N) = Color(P) = RED, Coloe(GP) = BLACK

--- Recoloring
    - Make GP -> RED
    - Uncle and Parent -> BLACK
    - N = GP (Repeat)
    => 2 Levels are Balanced
--- Rotations
    - 4 Cases (L-L, L-R, R-R, R-L)
    - Swap color of GP and P
        -- In case of L-L & R-R
            - P goes UP
            - GP goes DOWN
        -- In case of L-R & R-L
            - First in *L-R and *R-L
                - N goes UP
                - P goes down
            - Then in L-*R and R-*L
                - N goes UP
                - GP goes down as sibling with P
            --> To handle it in code 
                - In First step,
                    - Make N as P (N = P)
                    - Make P as N (P = N -> Parent)
                    - Then Swap
        => To balance Color on Level
    - N = P (Repeat)
    => 1 Level is Balanced
*/
void balanceRB(Node *root, Node *n) {
    Node *p, *gp; // parent & grandparent

    while(n != root && n->color == RED && n->parent->color == RED) {
        p = n -> parent;
        gp = n -> parent -> parent;

        if(p == gp -> l) {
            /*
                    gp
                    /   => L - _
                   p
            */

            Node *u = gp -> r; //Uncle
            
            if(u && u -> color == RED) {
                // Recoloring
                gp -> color = RED;
                p -> color = u -> color = BLACK;
                n = gp;
            } else {
                    // If Uncle is NULL or Uncle is Black -- Rotation
                    // Possible Cases L-R, L-L

                    if(n = p -> r) { // L-R
                        // *L-R
                        leftRotate(gp);
                        n = p;
                        p = n -> parent;
                    }

                    // L-L || L-R*
                    rightRotate(gp);
                    swap(p -> color, gp-> color);
                    n = p;
            }
        } else {
            /*
                gp
                 \    =>  R - _
                  p
            */

           Node *u = gp -> l;

           if(u && u -> color == RED) {
               // recoloring
               gp -> color = RED;
               p -> color = u -> color = BLACK;
               n = gp;
           } else {
               // Uncle is not available or BLACK -- Rotation

               if(n == p -> l) { // R-L
                   // *R-L
                   rightRotate(gp);
                   n = p;
                   p = n -> parent;
               }

               // R-R || R-*L
               leftRotate(gp);
               swap(p -> color, gp -> color);
               n = gp;
           }
        }
    }

    root -> color = BLACK;
}

void insertRB(int key) {
    Node *n = new Node(key);

    root = insertBST(root, n);

    balanceRB(root, n);
}

void inOrder(Node *root) {
    if(!root) return;
    inOrder(root -> l);
    cout << root -> key << " ";
    inOrder(root -> r);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, in; cin >> t;

    while(t--) {
        cin >> n;
        root = NULL;
        
        while(n--) {
            cin >> in;
            insertRB(in);
        }

        inOrder(root);
        cout << "\n";
    }

	return 0;
}

/*
--- Input ---
1
7
7 6 5 4 3 2 1
--- Output ---
1 2 3 4 5 6 7 
*/