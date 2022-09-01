#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

void rotateByN(struct Node **head, int n) {
    struct Node *h = *head, *t = *head, *newH = *head;

    while(t->next) {
        n--;
        t = t->next;
        if(n == 0) newH = t;
    }

    if(!newH) {
        cout<<"Cannot reverse"<<endl;
        return;
    }

    t->next = h;
    h->prev = t;
    newH->prev->next = NULL;
    newH->prev = NULL;

    *head = newH;

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

void print(struct Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    int x = 4;

    print(head);

    rotateByN(&head, x);

    print(head);

    return 0;
}
