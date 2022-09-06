/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* treeUtil(int in[], int pre[], int n, int inSt, int inEn, int &preIdx, map<int, int> &m) {
        if(preIdx == n || inSt > inEn) return NULL;
        
        int val = pre[preIdx++];
        
        Node* node = new Node(val);
        node->left = treeUtil(in, pre, n, inSt, m[val]-1, preIdx, m);
        node->right = treeUtil(in, pre, n, m[val]+1, inEn, preIdx, m);
        return node;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int, int> m;
        for(int i=0; i<n; i++) {
            m[in[i]] = i;
        }
        
        int preIdx = 0;
        return treeUtil(in, pre, n, 0, n-1, preIdx, m);
    }
};