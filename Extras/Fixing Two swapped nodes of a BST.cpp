class Solution
{
public:
    Node *prev;
    Node *first;
    Node *last;
    Node *middle;

    void inorder(struct Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL and root->data < prev->data)
        {

            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }

    struct Node *correctBST(struct Node *root)
    {
        // code here
        first = middle = last = NULL;
        prev = new Node(INT_MIN);

        inorder(root);

        if (first and last)
            swap(first->data, last->data);
        else if (first and middle)
            swap(first->data, middle->data);

        return root;
    }
};