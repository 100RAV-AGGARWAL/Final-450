//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(!root) return NULL;
   
   int mn = min(n1, n2);
   int mx = max(n1, n2);
   
   if(root->data == mn) return root;
   
   if(root->data == mx) return root;
   
   if(root->data > mn && root->data < mx) return root;
   
   if(root->data > mn && root->data > mx) return LCA(root->left, n1, n2);
   else if(root->data < mn && root->data < mx) return LCA(root->right, n1, n2);
   
   return NULL;
}