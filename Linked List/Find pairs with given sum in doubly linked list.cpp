#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
};

void pairSum(struct Node *head, int x)
{
    struct Node *start = head, *end = head;
    while(end->next) {
        end = end->next;
    } 

    bool flag = false;
    while(start != end && end->next != start) {
        int sum = start->data + end->data;
        if(sum == x) {
            flag = true;
            cout<<start->data<<", "<<end->data<<endl;
            start = start->next;
            end = end->prev;
        } else {
            if(sum < x) start = start->next;
            else end = end -> prev;
        }
    }

    if(!flag) cout << -1 << endl;
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
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
	int x = 9;

	pairSum(head, x);

	return 0;
}
