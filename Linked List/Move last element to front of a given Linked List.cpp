#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void moveLastToFirst() {
        Node *temp = head;

        if(!head || !head->next) return;

        while(temp->next->next) {
            temp = temp->next;
        }

        Node *tail = temp->next;
        temp->next = NULL;
        tail->next = head;
        head = tail;
    }

    void push(int d)
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    LinkedList ll;
    ll.push(5);
    ll.push(4);
    ll.push(3);
    ll.push(2);
    ll.push(1);

    cout << "Given linked list\n";
    ll.print();

    ll.moveLastToFirst();

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}