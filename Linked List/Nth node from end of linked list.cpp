
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       if(!head) return -1;
       
       Node *fast = head, *slow = head;
       
       int c = 0;
       
       while(fast) {
            c++;
            
            if(c < n) fast = fast->next;
            else break;
       }
       
       if(c < n) return -1;
       
       while(fast) {
           if(!fast->next) break;
           fast = fast->next;
           slow = slow->next;
       }
       
       return slow->data;
}
