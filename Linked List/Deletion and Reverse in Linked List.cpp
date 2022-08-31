/* structure for a node
struct Node
{
    int data;
    struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{

    // Your code goes here
    if ((*head)->next == *head && key == (*head)->data)
        *head = NULL;

    Node *prev = *head, *curr = (*head)->next;

    while (curr->next != *head)
    {
        if (curr->data == key)
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            return;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

/* Function to reverse the linked list */
void reverse(struct Node **head)
{

    // Your code goes here
    if (!(*head) || (*head)->next == *head)
        return;

    Node *tail = *head;

    while (tail->next != *head)
    {
        tail = tail->next;
    }

    Node *prev = tail, *curr = *head;

    while (curr->next != *head)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node *next = curr->next;
    curr->next = prev;

    *head = curr;
}
