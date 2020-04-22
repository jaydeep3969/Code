#include <bits/stdc++.h>
using namespace std;

#define p push

/* Given a tree, Print Bredth first traversal
   Complexity: Time: O(n)
 */

struct Node {
    int x;
    Node *l, *r;
    Node (int data) 
    { 
        x = data; 
        l = r = NULL; 
    } 
} *root;

void doBFT(Node *root) {
    if(!root)
        return;
    
    queue<Node *> q;
    q.p(root);
    cout << q.front() -> x << " ";

    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if(cur -> l) {
            q.push(cur -> l);
            cout << cur -> l -> x << " ";
        }

        if(cur -> r) {
            q.push(cur -> r);
            cout <<cur -> r -> x << " ";
        }
    }

    cout << "\n";
}

int main() {
    Node *tmp;
    root = new Node(10);
    root->l = new Node(9);
    root->r = new Node(-10);
    tmp = root -> l;
    tmp -> l =new Node(11);
    tmp = tmp -> l;
    tmp -> r = new Node(15);
    tmp = root -> r;
    tmp -> l = new Node(16);
    tmp -> r = new Node(21);
    tmp -> l -> l = new Node(18);
    tmp -> r -> r = new Node(19);

    /*
            10
            /\
           9  -10
          /    /\
         11  16  21
         \   /    \
         15 18    19
    */

    doBFT(root);
	return 0;
}

/*
--- Output ---
10 9 -10 11 16 21 15 18 19
*/