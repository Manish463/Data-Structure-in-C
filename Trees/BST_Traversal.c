#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *left;
    int data;
    struct Node *right;
} TreeNode;

TreeNode *createNode(int val){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = val;
    return newNode;
}

void InOrder(TreeNode *root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d\t",root->data);
        InOrder(root->right);
    }
}
void PreOrder(TreeNode *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        InOrder(root->left);
        InOrder(root->right);
    }
}
void PostOrder(TreeNode *root){
    if(root!=NULL){
        InOrder(root->left);
        InOrder(root->right);
        printf("%d\t",root->data);
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

    TreeNode *root = createNode(9);

    TreeNode *p1 = createNode(8);
    TreeNode *c1 = createNode(6);
    TreeNode *d1 = createNode(5);
    TreeNode *d2 = createNode(7);

    root->left = p1;
    p1->left= c1;
    c1->left=d1;
    c1->right=d2;


    TreeNode *p2 = createNode(11);
    TreeNode *e1 = createNode(10);
    TreeNode *e2 = createNode(14);
    
    root->right = p2;
    p2->left = e1;
    p2->right = e2;

    printf("\n InOrder Traversal of BST :\n");
    InOrder(root);
    
    printf("\n PreOrder Traversal of BST :\n");
    PreOrder(root);
    
    printf("\n PostOrder Traversal of BST :\n");
    PostOrder(root);


    
    return 0;
}