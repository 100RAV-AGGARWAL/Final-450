/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    void util(Node* &curr, Node* &prev, int& maxNum) {
        if(!curr) return;
        
        util(curr->next, curr, maxNum);
        
        maxNum = max(maxNum, curr->data);
        if(curr->data < maxNum) {
            prev->next = curr->next;
        }
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head || !head->next) return head;
        
        Node *curr = head->next, *prev = head;
        int maxNum = INT_MIN;
        
        util(curr, prev, maxNum);
        if(head->data < head->next->data) head = head->next;
        
        return head;
    }
    
};
   
