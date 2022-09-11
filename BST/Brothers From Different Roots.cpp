/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void inorder(Node* root, map<int, int> &m) {
        if(!root) return;
    
        inorder(root->left, m);
        m[root->data]++;
        inorder(root->right, m);
    }
    
    //GIVING TLE
    // void countUtil(Node* root, map<int, int> m, int x, int &cnt) {
    //     if(!root) return; 
        
    //     if(m.find(x - root->data) != m.end()) cnt++;
        
    //     countUtil(root->left, m, x, cnt);
        
    //     if(root->data < x)
    //         countUtil(root->right, m, x, cnt);
    // }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        map<int, int> m1, m2;
        inorder(root1, m1);
        inorder(root2, m2);
        
        int cnt=0;
        
        for(auto it : m1) {
            if(m2.find(x - it.first) != m2.end())cnt++;
        }
        return cnt;
    }
};