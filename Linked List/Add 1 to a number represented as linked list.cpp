/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head) {
        Node *prev = NULL, *curr = head, *next = head->next;

        if (next == NULL)
            return head;

        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            if (next)
                next = next->next;
        }

        head = prev;
        return head;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *revHead = reverse(head);
        
        Node *temp = revHead, *tail = head;
        int c = 1;
        while(temp) {
            int num = temp->data + c;
            temp->data = num % 10;
            c = num / 10;
            
            if(temp->next == NULL) tail = temp;
            
            temp = temp->next;
        }
        
        if(c) {
            Node *newNode = new Node(1);
            tail->next = newNode;
        }
        
        return reverse(revHead);
    }
};