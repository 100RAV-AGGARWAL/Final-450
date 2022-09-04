/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   if(!root) return {};
   
   vector<int> ans;
   queue<Node*> q;
   
   q.push(root);
   
   //marking end of curr level
   q.push(NULL);
   
   ans.push_back(root->data);
   
   while(!q.empty()) {
        Node *top = q.front();
        q.pop();
        
        if(top) {
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        } else {
            if(!q.empty()) {
                ans.push_back(q.front()->data);
                q.push(NULL);
            }
        }
   }
   
   return ans;
}