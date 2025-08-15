#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
} TreeNode;

TreeNode *createNode(int val)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = val;
    return newNode;
}

TreeNode *Insertion(TreeNode *root, int val)
{
    TreeNode *prev;
    TreeNode *n;
    TreeNode *newNode = createNode(val);
    if (root == NULL)
    {
        printf("The BST is NULL\n");
        return newNode;
    }
    else
    {
        n = root;
        while (n != NULL)
        {
            prev = n;
            if (val == n->data)
            {
                printf("The Node already exists.\n");
                return root;
            }
            else if (val > n->data)
            {
                n = n->right;
            }
            else
            {
                n = n->left;
            }
        }

        if (val > prev->data)
        {
            prev->right = newNode;
        }
        else
        {
            prev->left = newNode;
        }
        return root;
    }
}

TreeNode *findMin(TreeNode *root)
{
    TreeNode *n = root;
    while (n->right != NULL)
    {
        n = n->right;
    }
    return n;
}

// Function to delete a node from the BST
TreeNode *inOrderPredecessor(TreeNode *node)
{
    node = node->left;
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

TreeNode *deleteNode(TreeNode *node, int key)
{
    TreeNode *iPre = NULL;

    if (node == NULL)
    {
        printf("The value is not exist in the tree.\n");
        return NULL;
    }
    if (node->left == NULL && node->right == NULL)
    {
        if (node->data == key)
        {
            free(node);
            return NULL;
        }
    }

    if (key < node->data)
    {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = deleteNode(node->right, key);
    }
    else
    {
        iPre = inOrderPredecessor(node);
        node->data = iPre->data;
        node->left = deleteNode(node->left, iPre->data);
    }
    return node;
}

void InOrder(TreeNode *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d\t", root->data);
        InOrder(root->right);
    }
}

int main()
{
    /*
              9
             / \
            8  11
           /  /  \
          6  10   14
         / \
        5   7
    */

    // Creating the BST
    TreeNode *root = createNode(9);

    TreeNode *p1 = createNode(8);
    TreeNode *c1 = createNode(6);
    TreeNode *d1 = createNode(5);
    TreeNode *d2 = createNode(7);

    root->left = p1;
    p1->left = c1;
    c1->left = d1;
    c1->right = d2;

    TreeNode *p2 = createNode(11);
    TreeNode *e1 = createNode(10);
    TreeNode *e2 = createNode(14);

    root->right = p2;
    p2->left = e1;
    p2->right = e2;

    // Operations on the BST
    printf("\n Traversal before opration: \n");
    InOrder(root);

    // root = Insertion(root,24);
    root = deleteNode(root, 8);

    printf("\n Traversal after insertion: \n");
    InOrder(root);

    return 0;
}