class Solution
{
public:
    int length(Node *head) {
        int len = 0;
        Node *temp = head;
        
        while(temp) {
            len++;
            temp = temp->next;
        }
        
        return len;
    }
    
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        int len1 = length(head1), len2 = length(head2);
        
        int diff = len1 - len2;
        
        Node *t1 = head1, *t2 = head2;
        
        if(diff > 0) {
            while(diff--) {
                t1 = t1->next;
            }
        } else if(diff < 0) {
            while(diff++) {
                t2 = t2->next;
            }
        }
        
        while(t1 && t2) {
            if(t1 == t2) return t1->data;
            else {
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        
        return -1;
    }
};