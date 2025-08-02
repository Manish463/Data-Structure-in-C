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

TreeNode* Insertion(TreeNode *root ,int val){
    TreeNode* prev;
    TreeNode* n;
    TreeNode *newNode = createNode(val);
    if(root==NULL){
        printf("The BST is NULL\n");
        return newNode;
    }
    else{
        n = root;
        while(n!=NULL){
            prev = n;
            if(val==n->data){
                printf("The Node already exists.\n");
                return root;
            }
            else if(val>n->data){
                n= n->right;
            }
            else{
                n = n->left;
            }
        }

        if(val>prev->data){
            prev->right = newNode;
        }
        else{
            prev->left = newNode;
        }
        return root;
    }
}


TreeNode* findMin(TreeNode *root){
    TreeNode *n = root;
    while(n->right!=NULL){
        n = n->right;
    }
    return n;
}

// Incomplete
TreeNode* Deletion(TreeNode *root,int val){
    TreeNode *prev;
    TreeNode *n;
    TreeNode *rightNode;
    if(root==NULL){
        printf("The BST is NULL");
        return NULL;
    }
    else{
        n = root;
        prev = n;
        while(n!=NULL){
            if(n->data==val){
                break;
            }
            else if(val>n->data){
                prev = n;
                n= n->right;
            }
            else{
                prev = n;
                n= n->left;
            }
        }
        if(n==NULL){
            printf("Node not found");
            return root;
        }
        else if(n->right==NULL && n->left == NULL){
            if(prev->left == n){
                prev->left = n->left;
            }
            else{
                prev->right = n->right;
            }
            free(n);
            return root;
        }
        else if(n->left != NULL && prev->left == n){
            prev->left = n->left;
            return root;
        }
        else if(n->right != NULL && prev->right == n){
            prev->left = n->left;
            return root;
        }
        else{
            rightNode = findMin(n->left);
            rightNode->right = n->right;
            if(n==root){
                root= n->left;
            }
            else{
                if(prev->left==n){
                    prev->left=rightNode;
                }
                else{
                    prev->right=rightNode;
                }
            }
            free(n);
            return root;
        }
    }
}




void InOrder(TreeNode *root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d\t",root->data);
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

    root = Insertion(root,4);

    root = Deletion(root,11);
    printf("\n InOrder Traversal of BST :\n");
    InOrder(root);
    // printf("\n%d\n",find_right(root)->data);


    
    return 0;
}