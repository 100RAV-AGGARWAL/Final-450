/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> v;
   
   if(!root) return v;
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()) {
       Node *curr = q.front();
       q.pop();
       
       while(curr) {
           if(curr->left) q.push(curr->left);
           
           v.push_back(curr->data);
           curr = curr->right;
       }
   }
   
   return v;
}