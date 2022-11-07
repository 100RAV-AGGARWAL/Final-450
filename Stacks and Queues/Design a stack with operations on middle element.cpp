#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
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
            top->prev = temp;
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

    Node* findMiddle() {
        Node *fast = top, *slow = top;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void deleteMiddle() {
        Node* mid = findMiddle();

        if(mid == top) top=top->next;
        else {
            mid->prev->next = mid->next;
            mid->next->prev = mid->prev;
            delete mid;
        }

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

    cout<<"Middle: "<<s1.findMiddle()->data<<endl;

    s1.deleteMiddle();

    s1.display();
    return 0;
}