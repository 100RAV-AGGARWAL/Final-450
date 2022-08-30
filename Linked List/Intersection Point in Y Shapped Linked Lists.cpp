/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int cnt1 = 0, cnt2 = 0;
    
    Node *h1 = head1;
    while(h1) {
        cnt1++;
        h1 = h1->next;
    }
    h1 = head1;
    
    Node *h2 = head2;
    while(h2) {
        cnt2++;
        h2 = h2->next;
    }
    h2 = head2;
    
    int diff = abs(cnt1-cnt2);
    if(cnt1>=cnt2) {
        while(diff--) {
            h1 = h1->next;
        }
    } else {
        while(diff--) {
            h2 = h2->next;
        }
    }
    
    while(h1 && h2) {
        if(h1 == h2) return h1->data;
        
        h1 = h1->next;
        h2 = h2->next;
    }
    
    return -1;
}
