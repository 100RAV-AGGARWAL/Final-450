/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int cnt0 = 0, cnt1 = 0;
        
        Node *h = head;
        while(h) {
            if(h->data == 0) cnt0++;
            else if(h->data == 1) cnt1++;
            h = h->next;
        }
        
        h = head;
        
        while(h) {
            if(cnt0-- > 0) {
                h->data = 0;
            } else if(cnt1-- > 0) {
                h->data = 1;
            } else {
                h->data = 2;
            }
            
            h = h->next;
        }
        
        return head;
        
    }
};