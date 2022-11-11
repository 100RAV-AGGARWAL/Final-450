#include <bits/stdc++.h>
using namespace std;

class CQueue
{
    int *arr;
    int size, rear, front;

public:
    CQueue(int s)
    {
        rear = front = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int data)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Queue Full" << endl;
            return;
        }

        if (rear == -1)
        {
            front=0;
            rear=0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = data;
    }

    void deQueue()
    {
        if (front == -1)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        cout << ans << " popped" << endl;
    }

    void displayQueue()
    {
        if (front == -1)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Elements in Circular Queue are: ";
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout<<arr[i]<<" ";
        }
        else
        {
            for (int i = front; i < size; i++)
                cout<<arr[i]<<" ";

            for (int i = 0; i <= rear; i++)
                cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int
main()
{
    CQueue q(5);

    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    q.deQueue();
    q.deQueue();

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20);
    return 0;
}