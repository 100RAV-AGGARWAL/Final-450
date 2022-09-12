
/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* util(int pre[], int start, int end) {
        Node *root = newNode(pre[start]);
        
        int upperBound = start+1;
        
        while(upperBound <= end && pre[upperBound] < pre[start]) upperBound++;
        
        if(upperBound == start+1) root->left = NULL;
        else {
            root->left = util(pre, start+1, upperBound-1);
        }
        
        if(upperBound > end) root->right = NULL;
        else {
            root->right = util(pre, upperBound, end);
        }
        
        return root;
    }
    
    Node* post_order(int pre[], int size)
    {
        //code here
        if(!size) return NULL;
        
        return util(pre, 0, size-1);
    }
};