#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef vector<int> vi;

/*
    Given a BST and target sum.
    Find the path from root to leaf for which the sum of all nodes becomes SUM.

    Complexity: O(n) -- All node to be visited in worst case
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

bool findLeafToRootSum(Node *root, int sum, vi &res) {
    if(root->l == NULL && root->r == NULL) {
        if(root->x == sum) {
            res.pb(root->x);
            return true;
        }
        return false;
    }

    if(root->l && findLeafToRootSum(root->l, sum-(root->x), res)) {
        res.pb(root->x);
        return true;
    }

    if(root->r && findLeafToRootSum(root->r, sum-(root->x), res)) {
        res.pb(root->x);
        return true;
    }

    return false;
}

void inOrder(Node *root){}

void insertInBST(Node* root, int i){}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

   int t, n, sum; cin >> t;

    while(t--){
        cin >> n >> sum;
        
        int i;
        cin >> i;
        n--;
        
        root = new Node(i);
        vi res;
        while(n--){
            cin >> i;
            insertInBST(root, i);
        }

        cout << "Inorder:\n";
        inOrder(root);
        cout << "\n";
        
        if(findLeafToRootSum(root, sum, res))  {
            for(int i: res)
                cout << i << " ";
        } else 
            cout << -1;
        cout << "\n";
    }   
	return 0;
}


/*
--- Input ---
2
6 37
10 16 5 6 -3 11
6 5
10 16 5 6 -3 11
--- Output ---
Inorder:
-3 5 6 10 11 16 
11 16 10 
Inorder:
-3 5 6 10 11 16 
-1
*/