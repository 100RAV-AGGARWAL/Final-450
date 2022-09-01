/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node *merge(Node *left, Node *right) {
    if(!left) return right;
    if(!right) return left;
    
    Node *ans = new Node(-1);
    Node *temp = ans;
    
    while(left && right) {
        if(left->data < right->data) {
            temp->bottom = left;
            temp = left;
            left = left->bottom;
        } else {
            temp->bottom = right;
            temp = right;
            right = right->bottom;
        }
    }
    
    while(left) {
        temp->bottom = left;
            temp = left;
            left = left->bottom;
    }
    
    while(right) {
        temp->bottom = right;
            temp = right;
            right = right->bottom;
    }
    
    return ans->bottom;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(!root || !root->next) return root;
   
   Node *first = root, *second = flatten(root->next);
   
   Node *ans = merge(first, second);
   return ans;
}
