#include <bits/stdc++.h>
using namespace std;

/* https://youtu.be/13m9ZCB8gjw
   Given a BT and two nodes of it, find lowest common ancestor of those nodes
   
   1. Going into left nodes recursively, 
      If nodes value == l or r then return that node
      else NULL

   Optimization Step: 
        If(left != NULL & left's value is neither l nor r) 
        then that means LCA is found somewhere down
        so no need to explore right
        => return that found LCA (left)
   
   2. Going back to parent node and then explore its right child 
      Step 1 repeated

   3. Going back to parent 
      If(both left & right not NULL ) return parent node
      If(one of them is NULL) then return Node which is not null
      else return NULL (If both are NULL)

    Complexity: Time O(n)
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

Node* LCA_BT(Node *root, int l, int r) {
    if(!root) return NULL;

    if(root -> x == l || root -> x == r) 
        return root;

    Node* left = LCA_BT(root -> l, l, r);

    // optimization step
    if (left && left -> x != l && left -> x != r)
        return left;

    Node *right = LCA_BT(root -> r, l, r);

    if(left && right) return root;
    if(left) return left;
    if(right) return right;
    return NULL;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, l,r;

    Node *tmp;
    root = new Node(3);
    root -> l = new Node(6);
    root -> r = new Node(8);

    tmp = root -> l;
    tmp -> l = new Node(2);
    tmp -> r = new Node(11);
    tmp = tmp -> r;
    tmp -> l = new Node(9);
    tmp -> r = new Node(5);

    tmp = root -> r;
    tmp -> r = new Node(13);
    tmp -> r -> l = new Node(7);

    cin >> n;
    while(n--) {
        cin >> l >> r;

        Node *anc = LCA_BT(root, l, r);

        if(anc)
            cout << LCA_BT(root, l, r) -> x << "\n";
    }

	return 0;
}

/*
             3
            /  \
          6     8
         /\      \
        2  11     13
           /\     /
          9  5   7
*/

/*
---Input---
8
2 5
2 2
11 2
11 9
2 7
3 7
7 8
13 9
---Output---
6
2
6
11
3
3
8
3
*/