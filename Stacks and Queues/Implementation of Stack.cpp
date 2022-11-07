#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

class Stack {
    public: 
    Node *top;
    
    Stack() {
        top = NULL;
    }

    void push(int data) {
        Node *temp = new Node(data);

        if(top) {
            temp -> next = top; 
        }

        top = temp;
    }

    void pop() {
        if(!top) {
            cout<<"Stack empty\n";
            return;
        }

        cout<<top->data<<" popped from stack\n";

        top = top->next;
    }

    void display() {
        Node *temp = top;

        while(temp) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.display();
    
    s1.pop();
    s1.pop();

    s1.display();

    return 0;
}