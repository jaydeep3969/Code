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

void inOrder(Node *root){
    if(!root)
        return;

    inOrder(root -> l);
    cout << root -> x << " ";
    inOrder(root -> r);
}

void postOrder(Node *root){
    if(!root)
        return;

    postOrder(root -> l);
    postOrder(root -> r);
    cout << root -> x << " ";
}

void preOrder(Node *root){
    if(!root)
        return;

    cout << root -> x << " ";
    preOrder(root -> l);
    preOrder(root -> r);
}

Node* deleteNode(Node* root, int key) {
    if(!root) return root;

    if(root -> x > key)
        root -> l = deleteNode(root -> l, key);
    else if(root -> x < key)
        root -> r = deleteNode(root -> r, key);
    else {
        // Checking if node to be deleted is having only one child
        if(!root -> l) {
            Node *tmp = root -> r;
            delete root;
            return tmp;
        }

        if(!root -> r) {
            Node *tmp = root -> l;
            delete root;
            return tmp;
        }

        // If both children are available, then find successor
        // Assign key of Successor to the node to be deleted
        // Delete Successor
        Node *prev = root, *cur = root -> r;

        while(cur -> l) {
            prev = cur;
            cur = cur -> l;
        }
        
        if(prev != root)
            prev -> l = cur -> r;
        else
            prev -> r = cur -> r; // If there's no successor

        root -> x = cur -> x;
        delete cur;
    }
    return root;
}

void insertInBST(Node* root, int i){
    if((root -> x) < i){
        if(!root -> r) {
            root -> r = new Node(i);
            return;
        }
        else
            insertInBST(root->r, i);
    }
    else {
        if(!root -> l) {
            root -> l = new Node(i);
            return;
        }
        else
            insertInBST(root->l, i);
    }
}

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
        while(n--){
            cin >> i;
            insertInBST(root, i);
        }

        cout << "InOrder:\n";
        inOrder(root);
        cout << "\n";

        cout << "PreOrder:\n";
        preOrder(root);
        cout << "\n";

        cout << "PostOrder:\n";
        postOrder(root);
        cout << "\n";
    }   
	return 0;
}