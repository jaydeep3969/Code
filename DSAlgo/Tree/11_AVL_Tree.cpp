#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, height;
    Node *l, *r;
    Node (int k) 
    { 
        key = k; 
        height = 1;
        l = r = NULL; 
    } 
} *root;

int height(Node* n) {
    if(!n) return 0;
    return n -> height;
}

int getBalance(Node *n) {
    if(!n) return 0;
    return height(n->l) - height(n->r);
}

Node* leftRotate(Node *x) {
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

   y -> l = x;
   x -> r = T2;

   x->height = max(height(x->l), height(x->r)) + 1;
   y->height = max(height(y->l), height(y->r)) + 1;

   return y;
}

Node* rightRotate(Node *x) {
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

   y -> r = x;
   x -> l = T2;

   x->height = max(height(x->l), height(x->r)) + 1;
   y->height = max(height(y->l), height(y->r)) + 1;

   return y;
}

Node* findInorderSuccessor(Node *n) {
    if(!n || !n->r) return NULL;
    
    n = n->r;
    while(n->l)
        n = n->l;

    return n;
}

/*
Time Complexity :  O(log n)
h: Height of the tree
=> In normal BST, it is O(h)
--> It is same here but in AVL, the tree is always balanced => h = log n
--> The rotation takes constant time as there is only changes in some pointers
--> GetBalance() and Height() takes constant time
*/
Node* insertAVL(Node *root, int key) {
    if(!root) return new Node(key);

    if(root->key > key)
        root -> l = insertAVL(root->l, key);
    else if(root->key < key)
        root -> r = insertAVL(root->r, key);
    else 
        return root; //In AVL -- No same node allowed

    root -> height = max(height(root->l), height(root->r)) + 1;

    int balance = getBalance(root);

    if(balance > 1) {
        if(key > root->l->key) // *L-R
            root -> l = leftRotate(root -> l);
            
        return rightRotate(root);  // L-*R || *(L-L)
    }

    if(balance < -1) {
        if(key < root->r->key) // *R-L
            root -> r = rightRotate(root -> r);
            
        return leftRotate(root);  // R-*L || *(R-R)
    }

    return root; // If already balanced
}

// O(log n)
Node* deleteAVL(Node *root, int key) {
    if(!root)
        return root;
    
    if(root -> key > key)
        root -> l = deleteAVL(root->l, key);
    else if(root -> key < key)
        root -> r = deleteAVL(root->r, key);
    else {
        //Node to be deleted found
        if(!root -> l || !root -> r) { // Only one child --OR-- no child
            Node *node = root -> l ? root -> l: root -> r;
            Node *del = root;
            root = node;
            free(del);
        } else { // Both Child Available
            Node *suc = findInorderSuccessor(root);
            root -> key = suc -> key; // Copying successor's key to node to be deleted
            root -> r = deleteAVL(root->r, suc->key);
        }
    }

    if(!root) return NULL;

    root -> height = max(height(root->l), height(root->r)) + 1;

    int balance = getBalance(root);

    if(balance > 1) {
        if(getBalance(root -> l) < 0) // *L-R
            root -> l = leftRotate(root -> l);
            
        return rightRotate(root);  // L-*R || *(L-L)
    }

    if(balance < -1) {
        if(getBalance(root -> r) > 0) // *R-L
            root -> r = rightRotate(root -> r);
            
        return leftRotate(root);  // R-*L || *(R-R)
    }

    return root; // If already balanced
}

void inOrder(Node *root) {
    if(!root) return;
    inOrder(root -> l);
    cout << root -> key << " ";
    inOrder(root -> r);
}

void preOrder(Node *root) {
    if(!root) return;
    cout << root -> key << " ";
    preOrder(root -> l);
    preOrder(root -> r);
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
            root = insertAVL(root, in);
        }

        preOrder(root);
        cout << "\n";

        cin >> n;
        while(n--) {
            cin >> in;
            root = deleteAVL(root, in);
        }

        preOrder(root);
        cout << "\n";
    }

	return 0;
}

/*
--- Input ---
1
9
9 5 10 0 6 11 -1 1 2
3
1 10 11
---
6
10 20 30 40 50 25
--- Output ---
9 1 0 -1 5 2 6 10 11 
2 0 -1 6 5 9 
*/