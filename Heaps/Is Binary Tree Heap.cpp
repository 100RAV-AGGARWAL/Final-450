// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNode(struct Node* tree) {
        if(!tree) return 0;
        
        return 1 + countNode(tree->left) + countNode(tree->right);
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        if(tree == NULL) {
            return true;
        }
        
        int cnt = countNode(tree);
        
        if(isCBT(tree, cnt, 0) && isMaxOrder(tree)) return true;
        else return false;
    }
    
    bool isCBT(struct Node* root, int count, int i) {
        if(!root) return true;
        
        if(i >= count) return false;
        
        if(isCBT(root->left, count, 2*i+1) && isCBT(root->right, count, 2*i+2)) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isMaxOrder(struct Node* root) {
        if(root == NULL) {
            return true;
        }
        
        if(!root->left && !root->right) return true;
        
        if(!root->left) {
            return (root->data > root->right->data);
        } else if(!root->right) {
            return (root->data > root->left->data);
        } else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            if(left && right && (root->data > root->right->data) && (root->data > root->left->data)) 
                return true;
            else 
                return false;
        }
    }
};