#include <bits/stdc++.h>
using namespace std;

/* Given a tree, Print All Traversals in Interative way */

struct Node {
    int x;
    Node *l, *r;
    Node (int data) 
    { 
        x = data; 
        l = r = NULL; 
    } 
} *root;

void postOrderItr() {
    if(!root) return;

    stack<Node *> s1,s2;

    s1.push(root);
    
    while(!s1.empty()) {
        Node *cur = s1.top();
        s2.push(cur);
        s1.pop();

        if(cur -> l)
            s1.push(cur -> l);

        if(cur -> r)
            s1.push(cur -> r);
    }

    while(!s2.empty()) {
        cout << s2.top() -> x << " ";
        s2.pop();
    }
}

void postOrderItrSingleStack() {
    if(!root) return;

    stack<Node *> s;

    Node *cur = root;

    while(cur || !s.empty()) {
        if(cur) {
            s.push(cur);
            cur = cur -> l;
        } else {
            Node *tmp = s.top() -> r;

            if(!tmp) {
                tmp = s.top(); s.pop();

                cout << tmp -> x << " ";

                while(!s.empty() && tmp == s.top() -> r) {
                    tmp = s.top(); s.pop();
                    cout << tmp -> x << " ";
                }
            } else
                cur = tmp;
        }
    }
}

void postOrder(Node *root) {
    if(!root) return;

    postOrder(root -> l);
    postOrder(root -> r);
    cout << root -> x << " ";
}

void preOrderItr() {
    if(!root) return;

    stack<Node *> s;

    s.push(root);
    while(!s.empty()) {
        Node *cur = s.top(); s.pop();
        cout << cur -> x << " ";

        if(cur -> r)
            s.push(cur -> r);

        if(cur -> l) 
            s.push(cur -> l);
    }
}

void preOrder(Node *root) {
    if(!root) return;

    cout << root -> x << " ";
    preOrder(root -> l);
    preOrder(root -> r);
}

void inOrderItr() {
    if(!root) return;
    stack<Node *> s;

    s.push(root);
    while(s.top() -> l)
        s.push(s.top() -> l);

    while(!s.empty()) {
        Node *cur = s.top(); s.pop();
        cout << cur -> x << " ";
        
        if(cur -> r) {
            s.push(cur -> r);
            while(s.top() -> l)
                s.push(s.top() -> l);
        }
    }
}

void inOrder(Node *root) {
    if(!root) return;

    inOrder(root -> l);
    cout << root -> x << " ";
    inOrder(root -> r);
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

    cout << "postOrder : ";
    postOrder(root);
    cout << "\n";

    cout << "postOrderItr : ";
    postOrderItr();
    cout << "\n";

    cout << "postOrderItrSingleStack : ";
    postOrderItrSingleStack();
    cout << "\n";

    cout << "preOrder : ";
    preOrder(root);
    cout << "\n";

    cout << "preOrderItr : ";
    preOrderItr();
    cout << "\n";

    cout << "inOrder : ";
    inOrder(root);
    cout << "\n";

    cout << "inOrderItr : ";
    inOrderItr();
    cout << "\n";

	return 0;
}

/*
--- Output ---
postOrder : 15 11 9 18 16 19 21 -10 10
postOrderItr : 15 11 9 18 16 19 21 -10 10
postOrderItrSingleStack : 15 11 9 18 16 19 21 -10 10
preOrder : 10 9 11 15 -10 16 18 21 19
preOrderItr : 10 9 11 15 -10 16 18 21 19
inOrder : 11 15 9 10 18 16 -10 21 19
inOrderItr : 11 15 9 10 18 16 -10 21 19
*/