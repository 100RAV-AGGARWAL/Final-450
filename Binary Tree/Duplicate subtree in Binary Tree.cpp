/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    bool isLeaf(Node* root) {
        return (!root->left && !root->right);    
    }
    
    string mapping(Node* root, map<string, int> &m) {
        if(!root) return "#";
        if(isLeaf(root)) return to_string(root->data);
        
        string str = to_string(root->data);
        
        string left = mapping(root->left, m);
        string right = mapping(root->right, m);
        
        str += (" " + left +" " + right);
        m[str]++;
        
        return str;
    }
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
         // code here
         if(!root) return 0;
         
         map<string, int> m;
         string temp = mapping(root, m);
         
         for(auto itr : m) {
             if(itr.second > 1) return 1;
         }
         
         return 0;
    }
};