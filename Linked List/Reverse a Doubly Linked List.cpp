/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
Node* reverseDLL(Node * head)
{
    //Your code here
    
    Node *curr = head;
    Node *ref = head;
    while(curr) {
        Node *next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        
        if(!next) ref = curr;
        curr = next;
    }
    
    return ref;
}