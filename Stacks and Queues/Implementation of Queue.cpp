#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *front, *rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        if (!front)
        {
            front = temp;
            rear = temp;
        }

        rear->next = temp;
        rear = temp;
    }

    void pop()
    {
        if (!front)
        {
            cout << "Queue empty\n";
            return;
        }

        cout << front->data << " popped from queue\n";

        front = front->next;
    }

    void display()
    {
        Node *temp = front;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    q1.display();

    q1.pop();
    q1.pop();

    q1.display();

    return 0;
}