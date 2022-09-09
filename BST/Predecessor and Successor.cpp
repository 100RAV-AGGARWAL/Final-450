void pred(Node *root, int key, Node *&pre)
{
    while (root)
    {
        if (root->key < key)
        {
            pre = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}

void succ(Node *root, int key, Node *&suc)
{
    while (root)
    {
        if (root->key > key)
        {
            suc = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // Your code goes here
    pred(root, key, pre);
    succ(root, key, suc);
}