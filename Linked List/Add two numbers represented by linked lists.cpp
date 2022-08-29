/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
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
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        
        if(!second) return first;
        if(!first) return second;
        
        Node *revFirst = reverse(first);
        Node *revSecond = reverse(second);
        
        Node *t1 = revFirst, *t2 = revSecond;
        
        int sum = t1->data + t2->data;
        Node *result = new Node(sum%10);
        
        int c = sum / 10;
        Node *t3 = result;
        
        t1 = t1->next;
        t2 = t2->next;
        while(t1 && t2) {
            sum = t1->data + t2->data + c;
            Node *n = new Node(sum%10);
            c = sum / 10;
            
            t3->next = n;
            t3 = n;
            t1 = t1->next;
            t2 = t2->next;
        }
        
        while(t1) {
            sum = t1->data + c;
            Node *n = new Node(sum%10);
            c = sum / 10;
            
            t3->next = n;
            t3 = n;
            t1 = t1->next;
        }
        
        while(t2) {
            sum = t2->data + c;
            Node *n = new Node(sum%10);
            c = sum / 10;
            
            t3->next = n;
            t3 = n;
            t2 = t2->next;
        }
        
        if(c) {
            Node *n = new Node(1);
            t3->next = n;
        }
        
        return reverse(result);
    }
};