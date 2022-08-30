/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
node* partition(node *head, node *tail) {
    node *pivot = head, *curr = head->next;
    
    while(curr != tail) {
        if(curr->data <= pivot->data) {
            swap(curr->data, pivot->data);
        }
        curr = curr->next;
    }
    return pivot;
}

void util(node *head, node *tail) {
    if(!head || !head->next || head==tail) return;
    
    node *mid = partition(head, tail);
    util(head, mid);
    util(mid->next, tail);
}

void quickSort(struct node **headRef) {
    util(*headRef, NULL);
}