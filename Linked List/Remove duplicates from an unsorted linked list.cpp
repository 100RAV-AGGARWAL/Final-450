/*
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
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     unordered_map<int, int> m;
     
     if(head == NULL || head->next == NULL) return head;
     
     Node *temp = head->next, *h = head;
     m[head->data]++;
     
     while(temp) {
        if(m.find(temp->data) == m.end()) {
            h->next = temp;
            h = temp;
            m[temp->data]++;
        }
        temp = temp->next;
     }
     
     h->next = NULL;
     
     return head;
     
    }
};