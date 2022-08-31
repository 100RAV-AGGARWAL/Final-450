#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

void tripletSum(struct Node *head, int x)
{
    bool flag = false;
    Node *temp = head;

    if(!temp || !temp->next || !temp->next->next) {
        cout<<-1<<endl;
        return;
    }

    while (temp->next->next)
    {
        struct Node *start = temp->next, *end = temp->next;
        while (end->next)
        {
            end = end->next;
        }

        while (start != end && end->next != start)
        {
            int sum = start->data + end->data + temp->data;
            if (sum == x)
            {
                flag = true;
                cout <<temp->data<<", "<< start->data << ", " << end->data << endl;
                start = start->next;
                end = end->prev;
            }
            else
            {
                if (sum < x)
                    start = start->next;
                else
                    end = end->prev;
            }
        }
        temp = temp->next;
    }
    if (!flag)
        cout << -1 << endl;
}

void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 17;

    tripletSum(head, x);

    return 0;
}
