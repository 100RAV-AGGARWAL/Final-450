//Function to count number of nodes in BST that lie in the given range.
class Solution{
public:
    void count(Node* root, int l, int h, int &cnt) {
        if(!root) return;
        
        if(root->data >= l && root->data <= h ){ 
            cnt++;
        }
            count(root->left, l, h, cnt);
            count(root->right, l, h, cnt);
        
    }
    
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      int cnt = 0;
      count(root, l, h, cnt);
      
      return cnt;
    }
};