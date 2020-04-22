#include <bits/stdc++.h>
using namespace std;

/* Given a tree, Print Level Order Traversal - Each Level in New Line */

struct Node {
    int x;
    Node *l, *r;
    Node (int data) 
    { 
        x = data; 
        l = r = NULL; 
    } 
} *root;

/* Using 2 Queues */
void twoQueues() {
    if(!root) return;

    queue<Node *> q1, q2;

    q1.push(root);

    while(!q1.empty() || !q2.empty()) {
        while(!q1.empty()) {
            Node *cur = q1.front();
            
            if(cur -> l) 
                q2.push(cur -> l);
            
            if(cur -> r) 
                q2.push(cur -> r);

            cout << cur -> x << " ";
            q1.pop();
        }

        cout << "\n";

        while(!q2.empty()) {
            Node *cur = q2.front();
            
            if(cur -> l) 
                q1.push(cur -> l);
            
            if(cur -> r) 
                q1.push(cur -> r);

            cout << cur -> x << " ";
            q2.pop();
        }

        cout << "\n";
    }
}

/* Using 1 Queue and delimeter NULL to differentiate levels */
void queueDeli() {
    if(!root) return;

    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while(q.size() != 1) {
        Node *cur = q.front(); q.pop();
        
        if(!cur) {
            q.push(NULL);
            cout << "\n";
            continue;
        }

        if(cur -> l)
            q.push(cur -> l);

        if(cur -> r)
            q.push(cur -> r);

        cout << cur -> x << " ";
    }

    cout << "\n";
}

/* Using 1 Queue and counters of tracking the nodes in previous and current level */
void queueCounter() {
    if(!root) return;
    int cnt;
    int curCnt = 0;

    queue<Node *> q;

    q.push(root);
    cnt = 1;

    while(!q.empty()) {
        Node *cur = q.front(); q.pop();

        if(cnt == 0) {
            cnt = curCnt;
            curCnt = 0;
            cout << "\n";
        }

        if(cur -> l) {
            q.push(cur -> l);
            curCnt++;
        }

        if(cur -> r) {
            q.push(cur -> r);
            curCnt++;
        }

        cout << cur -> x << " ";
        cnt--;
    }

    cout << "\n";
}

/* Reverse Level Order Traversal (Bottom-Up) */
void revLOT() {
    if(!root) return;
    
    queue<Node *> q;
    stack<int> s;

    q.push(root);

    while(!q.empty()) {
        Node *cur = q.front(); q.pop();

        if(cur -> r)
            q.push(cur -> r);
        
        if(cur -> l)
            q.push(cur -> l);
        
        s.push(cur -> x);
    }

    while(!s.empty()) {
        cout << s.top() << " "; s.pop();
    }

    cout << "\n";
}

void revLOTlevelBylevel() {
    if(!root) return;
    
    queue<Node *> q;
    stack<int> s;

    q.push(root);
    q.push(NULL);

    while(q.size() != 1) {
        Node *cur = q.front(); q.pop();

        if(!cur) {
            q.push(NULL);
            s.push(-1);
            continue;
        }

        if(cur -> r)
            q.push(cur -> r);
        
        if(cur -> l)
            q.push(cur -> l);
        
        s.push(cur -> x);
    }

    while(!s.empty()) {
        int i = s.top(); s.pop();
        
        if(i == -1) 
            cout << "\n";
        else
            cout << i << " ";
    }

    cout << "\n";
}

int main() {
    Node *tmp;
    root = new Node(1);
    root->l = new Node(2);
    root->r = new Node(3);
    tmp = root -> l;
    tmp -> l =new Node(4);
    tmp -> r = new Node(5);
    tmp = tmp -> r;
    tmp -> l = new Node(8);
    tmp -> r = new Node(9 );
    tmp = root -> r;
    tmp -> l = new Node(6);
    tmp -> r = new Node(7);
    tmp -> r -> l = new Node(10);

    /*
                 1
                / \
               2   3
              /\   /\
             4  5 6  7
               /\    /
              8  9  10
    */

    cout << "Using 2 Queues:\n";
    twoQueues();
    cout << "Using 1 Queue and Delimeter:\n";
    queueDeli();
    cout << "Using 1 Queue and Counters:\n";
    queueCounter();
    cout << "Reverse Level Order Traversal (Bottom-Up) :\n";
    revLOT();
    cout << "Reverse LOT Level By Level :\n";
    revLOTlevelBylevel();
	return 0;
}

/*
--- Output ---
Using 2 Queues:
1
2 3
4 5 6 7 
8 9 10
Using 1 Queue and Delimeter:
1
2 3
4 5 6 7
8 9 10 
Using 1 Queue and Counters:
1
2 3
4 5 6 7
8 9 10
Reverse Level Order Traversal (Bottom-Up) :
8 9 10 4 5 6 7 2 3 1
Reverse LOT Level By Level :
8 9 10
4 5 6 7
2 3
1
*/