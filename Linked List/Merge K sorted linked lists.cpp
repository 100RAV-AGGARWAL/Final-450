/*Linked list Node structure

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

class Solution{
  public:
    Node *merge(Node *l1, Node *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        Node *result = new Node(-1);
        Node *temp = result;
        
        while(l1 && l2) {
            if(l1->data < l2->data) {
                result->next = l1;
                result = l1;
                l1 = l1->next;
            } else {
                result->next = l2;
                result = l2;
                l2 = l2->next;
            }
        }
        
        while(l1) {
            result->next = l1;
                result = l1;
                l1 = l1->next;
        }
        
        while(l2) {
            result->next = l2;
                result = l2;
                l2 = l2->next;
        }
        
        return temp->next;
    }
    
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node *ans = arr[0];
           for(int i=1; i<K; i++) {
               ans = merge(ans, arr[i]);
           }
           
           return ans;
    }
};
