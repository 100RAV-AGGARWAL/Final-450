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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(!head || !head->next) return head;
        
        Node *even = new Node(-1);
        Node *etail = even;
        Node *odd = new Node(-1);
        Node *otail = odd;
        
        Node *temp = head;
        
        while(temp) {
            if(temp->data % 2 == 0) {
                etail->next = temp;
                etail = temp;
                temp = temp->next;
            } else {
                otail->next = temp;
                otail = temp;
                temp = temp->next;
            }
        }
        
        if(even->next) {
           etail->next = odd->next;
           otail->next = NULL;
           head = even->next;
        } else {
            if(!even->next) {
                otail->next = NULL;
                head = odd->next;
            } else {
                etail->next = NULL;
                head = even->next;
            }
        }
        
        return head;
    }
};