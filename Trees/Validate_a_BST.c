#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

int isBST(TreeNode *root,int max,int min){
    if(root!=NULL){
        if (!(root->data<max && root->data>min)){
            return 0;
        }
        else{
            return isBST(root->left,root->data,min);
            return isBST(root->right,max,root->data);
        }
    }
    return 1;
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
    int x;    

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

    x = isBST(root,INT_MAX,INT_MIN);
    if(x){
        printf("Its a BST.\n");
    }
    else{
        printf("Its not a BST.\n");
    }
    printf("\nInOrder Traversal of BST :\n");
    InOrder(root);
    
    
    return 0;
}