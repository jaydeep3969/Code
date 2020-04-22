#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x;
    Node *l, *r;
    Node (int data) 
    { 
        x = data; 
        l = r = NULL; 
    } 
} *root;

/* Find Lowest Common Ancestor of given BST's two nodes*/

int LCA_BST(Node *root, int l, int r) {
    if(!root) return -1;

    // if((l < root->x && r > root->x) || root->x == l || root->x == r)
    //     return root->x;

    if(root -> x > r)
        return LCA_BST(root -> l, l , r);
    
    if(root -> x < l)
        return LCA_BST(root -> r, l , r);

    return root -> x;
}

void insertInBST(Node* root, int i){
    //pass
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

   int t, n; cin >> t;

    while(t--){
        cin >> n;
        
        int i;
        cin >> i;
        n--;
        
        root = new Node(i);
        while(n--){
            cin >> i;
            insertInBST(root, i);
        }

        int l,r;
        cin >> n;
        while(n--) {
            cin >> l >> r;
            cout << LCA_BST(root, min(l,r), max(l,r)) << "\n";
        }
    }   
	return 0;
}

/*
             10
            /  \
         -10    30
          \     /\
           8  25 60
          /\   \  \
         6  9  28  78
*/

/*
---Input---
1
10
10 -10 30 8 25 60 6 9 28 78
6
28 78
6 9
30 78
78 78
-10 -10
78 30
---Output---
30
8
30
78
-10
30
*/