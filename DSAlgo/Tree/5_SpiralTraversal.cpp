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

/* Using Queue and Stack with flag*/
void qStkST() {
    if(!root) return;

    queue<Node *> q;
    stack<int> s;

    q.push(root);
    q.push(NULL);

    bool flag = false;

    while(q.size() != 1) {
        Node *cur = q.front(); q.pop();

        if(!cur) {
            q.push(NULL);
            if(flag) {
                while(!s.empty()) {
                    cout << s.top() << " "; s.pop();
                }
            }

            flag = !flag;
            continue;
        }

        if(cur -> l)
            q.push(cur -> l);

        if(cur -> r)
            q.push(cur -> r);

        if(flag)
            s.push(cur -> x);
        else
            cout << cur -> x << " ";
    }

    while(!s.empty()) {
        cout << s.top() << " "; s.pop();
    }

    cout << "\n";
}

/* Using 2 stacks : Pushing into 1 as normal(l,r) and into another like queue(reverse order= r,l)*/
void twoStkST() {
    if(!root) return;

    stack<Node *> s1, s2;

    s1.push(root);
    while(!s1.empty() || !s2.empty()) {
        while(!s1.empty()) {
            Node *cur = s1.top(); s1.pop();

            if(cur -> l) 
                s2.push(cur -> l);

            if(cur -> r) 
                s2.push(cur -> r);

            cout << cur -> x << " ";
        }

        while(!s2.empty()) {
            Node *cur = s2.top(); s2.pop();

            if(cur -> r) 
                s1.push(cur -> r);

            if(cur -> l) 
                s1.push(cur -> l);

            cout << cur -> x << " ";
        }
    }

    cout << "\n";
}

/* Using dequeue */
void dqST() {
     if(!root) return;

    deque<Node *> dq;

    dq.push_front(root);
    dq.push_front(NULL);
    bool flag = true;  //flag for poping from front or back -- front: true, back: false

    while(dq.size() != 1) {
        Node *cur;

        cur = flag ? dq.front() : dq.back();
        
        if(!cur) {
            flag = !flag;
            continue;
        }

        if(flag) {
            if(cur -> l)
                dq.push_back(cur -> l);
        
            if(cur -> r)
                dq.push_back(cur -> r);
        } else {
            if(cur -> r)
                dq.push_front(cur -> r);

            if(cur -> l)
                dq.push_front(cur -> l) ;
        }

        cout << cur -> x << " ";
        flag ? dq.pop_front() : dq.pop_back();
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

    cout << "Using a queue and a stack:\n";
    qStkST();
    cout << "Using 2 stacks:\n";
    twoStkST();
    cout << "Using dequeue:\n";
    dqST();
	return 0;
}

/*
--- Output ---
Using a queue and a stack:
1 3 2 4 5 6 7 10 9 8
Using 2 stacks:
1 3 2 4 5 6 7 10 9 8
Using dequeue:
1 2 3 7 6 5 4 8 9 10
*/