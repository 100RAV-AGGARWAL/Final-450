/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* merge(Node *left, Node *right) {
        if(!left) return right;
        if(!right) return left;
        
        Node *result = NULL;
        
        if(left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        
        return result;
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        
        if(!head || !head->next) return head;
        
        Node *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            if(fast)
                slow = slow->next;
        }
        
        Node *right = slow ? slow->next : NULL;
        slow->next = NULL;
        
        head = mergeSort(head);
        right = mergeSort(right);
        
        Node *result = merge(head, right);
        return result;
    }
};