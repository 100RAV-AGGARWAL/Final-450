/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       
       if(!root) return ans;
       
       queue<Node*> q;
       q.push(root);
       q.push(NULL);
       ans.push_back(root->data);
       
       while(!q.empty()) {
           Node *top = q.front();
           q.pop();
           
           
           if(top) {
               if(top->right) q.push(top->right);
               if(top->left) q.push(top->left);
           } else {
               if(!q.empty()) {
                   ans.push_back(q.front()->data);
                   q.push(NULL);
               }
           }
       }
       
       return ans;
    }
};