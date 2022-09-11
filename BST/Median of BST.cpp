/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void count(Node* root, int &cnt) {
    if(!root) return;
    
    cnt++;
    count(root->left, cnt);
    count(root->right, cnt);
}

void calcMedian(Node* root, int cnt, int &i, float &med) {
    if(!root) return;
    
    calcMedian(root->left, cnt, i, med);
    
    if(i == cnt/2 || (i == (cnt/2)-1) && !(cnt%2)) med += root->data;
    i++;
    
    calcMedian(root->right, cnt, i, med);
}

float findMedian(struct Node *root)
{
      //Code here
      int cnt = 0, i = 0;
      float med = 0;
      
      count(root, cnt);
      
      calcMedian(root, cnt, i, med);
      
      return cnt%2 == 0 ? med/2 : med;
}