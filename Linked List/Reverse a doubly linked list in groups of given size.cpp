#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

struct Node* rotateInGroupofEven(struct Node *head, int n) {
    struct Node *curr = head, *prev=NULL;
    int c = 0;

    if(!head) return head;

    while(curr && c<n) {
        struct Node *next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;

        if(!next)
            prev = curr;

        curr = next;

        c++;
    }

    if(curr) {
        head->next = rotateInGroupofEven(curr, n);
        head->next->prev = head;
    }

    prev->prev = NULL;
    return prev;
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

    head = rotateInGroupofEven(head, x);

    print(head);

    return 0;
}

//////////////////////////////////////////////////////////////

// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
// 	int data;
// 	Node *next, *prev;
// };

// Node* getNode(int data)
// {
// 	Node* new_node = (Node*)malloc(sizeof(Node));

// 	new_node->data = data;
// 	new_node->next = new_node->prev = NULL;
// 	return new_node;
// }

// void push(Node** head_ref, Node* new_node)
// {
// 	new_node->prev = NULL;
// 	new_node->next = (*head_ref);
// 	if ((*head_ref) != NULL)
// 		(*head_ref)->prev = new_node;

// 	(*head_ref) = new_node;
// }

// Node* revListInGroupOfGivenSize(Node* head, int k)
// {
// 	Node *current = head;
// 	Node* next = NULL;
// 	Node* newHead = NULL;
// 	int count = 0;
	
// 	while (current != NULL && count < k)
// 	{
// 		next = current->next;
// 		push(&newHead, current);
// 		current = next;
// 		count++;
// 	}
	
// 	if (next != NULL)
// 	{
// 		head->next = revListInGroupOfGivenSize(next, k);
// 		head->next->prev = head;
// 	}
	
// 	newHead->prev = NULL;
// 	return newHead;
// }

// void printList(Node* head)
// {
// 	while (head != NULL) {
// 		cout << head->data << " ";
// 		head = head->next;
// 	}
// }

// int main()
// {
// 	Node* head = NULL;

// 	push(&head, getNode(2));
// 	push(&head, getNode(4));
// 	push(&head, getNode(8));
// 	push(&head, getNode(10));
	
// 	int k = 2;

// 	cout << "Original list: ";
// 	printList(head);

// 	head = revListInGroupOfGivenSize(head, k);

// 	cout << "\nModified list: ";
// 	printList(head);

// 	return 0;
// }
