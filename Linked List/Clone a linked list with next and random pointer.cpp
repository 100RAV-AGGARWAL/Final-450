class Solution
{
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *temp = head, *t = NULL, *newH = NULL;
        
        unordered_map<Node*, Node*> m;
        
        while(temp) {
            Node *n = new Node(temp->data);
            
            m[temp] = n;
            
            if(!newH) {
                newH = n;
                t = n;
            } else {
                t->next = n;
                t = n; 
            }
            temp = temp->next;
        }
        
        temp = head;
        while(temp) {
            (m[temp])->arb = m[temp->arb];
            temp = temp->next;
        }
        
        return newH;
    }

};