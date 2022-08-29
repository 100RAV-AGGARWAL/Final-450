/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    // your code goes here
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head->next, *h = head;

    while (temp)
    {
        if (h->data != temp->data)
        {
            h->next = temp;
            h = temp;
        }
        temp = temp->next;
    }

    h->next = NULL;

    return head;
}