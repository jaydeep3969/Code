#include <bits/stdc++.h>
using namespace std;

/* Given a BT, Find largest BST in it */

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

struct Res {
    bool flag;
    int size, min, max;

    Res(bool f, int s, int min1, int max1) {
        flag = f;
        size = s;
        min = min1;
        max= max1;
    }
};

/*
Doing PostOrder Traversal
Return : (isBST, sizeOfBST, minEleInBST, maxEleInBST)
-- If node is leaf node -> Then return (true, 1, node->value, node->value)
-- If node is inner node
    -> Check if the left and right node are BST and node->value is in between (left->max, right->min)
        If yes then return (true, size(left)+size(right)+1, left->min, right->max)
    -> Else return (false, max(size(left), size(right)), 0, 0)
*/
Res* findLargestBST(Node *root) {
    if(!root) return new Res(true, 0, INT_MAX, INT_MIN);

    Res *left = findLargestBST(root -> l);
    Res *right = findLargestBST(root -> r);

    if(!left -> flag || !right -> flag || left -> max > root -> x || right -> min < root -> x)
        return new Res(false, max(left->size, right->size), 0, 0);

    int min = root -> l ? left -> min : root -> x;
    int max = root -> r ? right -> max : root -> x;
    
    return new Res(true, left->size + right->size + 1, min, max);
}

Res* findLargestBST_my(Node *root) {
    // if(!root) return new Res(true, 0, INT_MAX, INT_MIN);
    if(!root) return NULL;

    Res *left = findLargestBST(root -> l);
    Res *right = findLargestBST(root -> r);
    
    if(left && right) {
        if(left -> flag && right->flag && left -> max <= root -> x && right -> min >= root -> x)
            return new Res(true, left->size + right -> size + 1, left -> min, right -> max);
        return new Res(false, max(left->size, right->size), 0, 0);
    }

    if(left) {
        if(left -> flag && left -> max <= root -> x)
            return new Res(true, left -> size + 1, left -> min, root -> x);
        return new Res(false, left -> size, 0, 0);
    }

    if(right) {
        if(right -> flag && right -> min >= root -> x)
            return new Res(true, right -> size + 1, root -> x, right -> max);
        return new Res(false, right -> size, 0, 0);
    }

    // cout << true << " " << 1 << " " << root -> x << " " << root -> x << "\n";
    return new Res(true, 1, root ->x, root->x);
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
    // tmp -> l -> l = new Node(22);
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

    Res *res = findLargestBST(root);

    cout << res -> size << "\n";

	return 0;
}

/*
--- Output ---
8
--> In the right side rooted at 50
*/