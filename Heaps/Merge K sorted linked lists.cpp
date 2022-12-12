typedef pair<int, Node*> p;
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node *head = new Node(-1), *temp;
           temp = head;
           int i;
           
           priority_queue<p, vector<p>, greater<p>> pq;
           p nd;
           
           for(int i=0; i<K; i++) {
               pq.push({arr[i]->data, arr[i]});
           }
           
           while(!pq.empty()) {
               nd = pq.top();
               pq.pop();
               
               temp->next = new Node(nd.first);
               temp = temp->next;
               
               if(nd.second -> next != 0) {
                   pq.push({nd.second->next->data, nd.second->next});
               }
           }
           
           return head->next;
           
    }
};