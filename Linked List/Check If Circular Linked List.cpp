/* Link list Node 
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

/* Should return true if linked list is circular, else false */
bool isCircular(Node *head)
{
   // Your code here
   Node *temp = head;
   
   while(temp) {
       if(temp->next == head) return true;
       
       temp = temp->next;
   }
   
   return false;
}
