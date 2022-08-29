/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<int, int> m;
    Node *result = NULL;
    Node *t3 = NULL;
    
    Node *t1 = head1;
    while(t1) {
        m[t1->data]++;
        t1 = t1->next;
    }
    
    Node *t2 = head2;
    while(t2) {
        if(m[t2->data] > 0) {
            Node *n = new Node(t2->data);
            if(result == NULL) {
                result = n;
                t3 = n;
            } else {
                t3->next = n;
                t3 = n;
            }
            
            m[t2->data]--;
        }
        t2 = t2->next;
    }
    
    return result;
}