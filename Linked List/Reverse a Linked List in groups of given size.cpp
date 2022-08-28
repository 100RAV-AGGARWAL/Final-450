class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node *prev = NULL, *curr = head;
        int temp = 0;

        if (head == NULL)
            return head;

        while (curr != NULL && temp<k)
        {
            node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            temp++;
        }

        if(curr != NULL) {
            node *rev = reverse(curr, k);
            head->next = rev;
        }
        return prev;
    }
};