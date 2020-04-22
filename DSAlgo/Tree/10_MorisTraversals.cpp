#include <bits/stdc++.h>
using namespace std;

/* Given a BT, Do Moris Traversals
    -- Traversals without use of stack/recursion
    -- Space : O(1)    => No extra space required
    -- Time : O(n)

    Basic idea is in iterative way once a node is visited and after its left
    subtree is explored, we have to go back to the root node and then we have to go to 
    right subtree to explore it
    -> So for that, we have to set a link bet.n the right most node on the left subtree 
       to the root node of the current tree
       -- Right most node on left subtree = predecessor of the node Bcoz link from that node to root
       So, we can go back to that node and while visiting the node second time 
           we can remove the earlier made temporary link => At end, final tree = initial tree
 */

// Complexity: O(n)

struct Node {
    int x;
    Node *l, *r;
    Node (int data) 
    { 
        x = data; 
        l = r = NULL; 
    } 
} *root;


void morisInOrder() {
    if(!root) return;

    Node* cur = root;

    while(cur) {
        if(!cur -> l) {
            /* If cur -> l is null, then no need to visit left and 
            as per InOrder (L R0 R), we have to print R0 and go to R */
            cout << cur -> x << " ";
            cur = cur -> r;
        } else {
            Node *predcsr = cur -> l;
            
            // going into right of left subtree to find predecessor
            while(predcsr -> r && predcsr -> r != cur)
                predcsr = predcsr -> r;

            if(!predcsr -> r) {
                // Setting the link
                predcsr -> r = cur;
                // now link is set and going to explore left subtree (L)
                cur = cur -> l;
            } else {
                /* Visited node second time 
                 Bcoz while exploring Left subtree we came back to root
                 using temp link
                 Now remove that link */
                predcsr -> r = NULL;
                // print the (R0)
                cout << cur -> x << " ";
                // explore right tree (R)
                cur = cur -> r;
            }
        }
    }
}

void inOrder(Node *root) {
    if(!root) return;
    inOrder(root -> l);
    cout << root -> x << " ";
    inOrder(root -> r);
}

void morisPreOrder() {
    if(!root) return;

    Node* cur = root;

    while(cur) {
        if(!cur -> l) {
            /* If cur -> l is null, then no need to visit left and 
            as per InOrder (R0 L R), we have to print R0 and go directly to R */
            cout << cur -> x << " ";
            cur = cur -> r;
        } else {
            Node *predcsr = cur -> l;
            
            // going into right of left subtree to find predecessor
            while(predcsr -> r && predcsr -> r != cur)
                predcsr = predcsr -> r;

            if(!predcsr -> r) {
                // Setting the link
                predcsr -> r = cur;
                // print the (R0)
                cout << cur -> x << " ";
                // now link is set and going to explore left subtree (L)
                cur = cur -> l;
            } else {
                /* Visited node second time 
                 Bcoz while exploring Left subtree we came back to root
                 using temp link
                 Now remove that link */
                predcsr -> r = NULL;
                // explore right tree (R)
                cur = cur -> r;
            }
        }
    }
}

void preOrder(Node *root) {
    if(!root) return;
    cout << root -> x << " ";
    preOrder(root -> l);
    preOrder(root -> r);
}

int main() {
    Node *tmp;
    root = new Node(25);
    root->l = new Node(18);
    root->r = new Node(50);
    tmp = root -> l;
    tmp -> l =new Node(19);
    tmp -> r =new Node(20);
    tmp -> l -> r = new Node(15);
    tmp = tmp -> r;
    tmp -> l = new Node(18);
    tmp -> r = new Node(25);
    tmp = root -> r;
    tmp -> l = new Node(35);
    tmp -> r = new Node(60);
    tmp = tmp -> l;
    tmp -> l = new Node(20);
    tmp -> r = new Node(40);
    tmp -> l -> r = new Node(25);
    tmp = root -> r -> r;
    tmp -> l= new Node(55);
    tmp -> r = new Node(70);

    /*
                   ---25---
                  /        \
                18          50
               / \        /   \
             19   20     35    60
             \    /\     / \   / \
             15 18  25  20 40 55 70
                         \
                         25
    */

    cout << "InOrder (Recursion) :\n" ;
    inOrder(root);
    cout << "\n";

    cout << "Moris InOrder :\n";
    morisInOrder();
    cout << "\n";

    cout << "PreOrder (Recursion) :\n" ;
    preOrder(root);
    cout << "\n";

    cout << "Moris PreOrder :\n";
    morisPreOrder();
    cout << "\n";

	return 0;
}

/*
--- Output ---
InOrder (Recursion) :
19 15 18 18 20 25 25 20 25 35 40 50 55 60 70 
Moris InOrder :
19 15 18 18 20 25 25 20 25 35 40 50 55 60 70 
PreOrder (Recursion) :
25 18 19 15 20 18 25 50 35 20 25 40 60 55 70 
Moris PreOrder :
25 18 19 15 20 18 25 50 35 20 25 40 60 55 70 
*/