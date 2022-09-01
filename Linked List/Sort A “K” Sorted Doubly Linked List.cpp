/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node *prev;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }
        };

*****************************************************************/

Node *sortedDll(Node *head, int k)
{
    // Write your code here
    if(!head || !head->next) return head;
    
    Node *h = head;
    
    while(h->next) {
        Node *temp = h->next;
        Node *minNode = h;
        
        int c = 0;
        while(temp && c < k) {
            if(temp->data < minNode->data) {
                minNode = temp;
            }
            temp=temp->next;
            c++;
        }
        
        swap(h->data, minNode->data);
        h = h->next;
    }
    return head;
}







