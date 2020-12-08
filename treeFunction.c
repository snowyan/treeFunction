#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;
typedef Node *NodePtr;

/*
1. Create a new Binary search tree node and assign value to it
2. insert(node,key)
   if root == NULL
      create a new node;
    if root->data  > key
       call the insert function with insert(root->left,key)
    if root->data <= key
       call the insert function with insert(root->right,key)

*/

void insert(NodePtr *curr, int key)
{
    if (*curr == NULL)
    {
        NodePtr newPtr = (Node *)malloc(sizeof(Node));
        if (newPtr != NULL)
        {
            newPtr->key = key;
            newPtr->left = NULL;
            newPtr->right = NULL;
            *curr = newPtr;
            // printf("the root is % d", key);
        }
        else
        {
            printf("Out of memory!!\n\n");
        }
    }
    else
    {
        if ((*curr)->key > key)
        {
            insert(&((*curr)->left), key);
            // printf("the left is %d", key);
        }
        else
        {
            insert(&((*curr)->right), key);
            //printf("the right is %d", key);
        }
    }
}
/*
Inorder traversal is one of the depth first tree traversal methods.

Inorder traversal of binary search tree will produce the output in acending order.

Inorder : Left - Root - Right

Algorithm:
1.Traverse the left subtree.
2.Print the root;
3.Traverse the right subtree.
*/

void traverseInorder(NodePtr curr)
{
    if (curr == NULL)
    {
        //printf("the tree is o");
        return;
    }
    traverseInorder(curr->left);
    printf("%d %s %s\n", curr->key, curr->left, curr->right);
    traverseInorder(curr->right);
}
/*
Preorder:Root - Left - Right
*/
void traversePreorder(NodePtr curr)
{
    if (curr == NULL)
    {
        return;
    }
    printf("%d \n", curr->key);
    traversePreorder(curr->left);
    traversePreorder(curr->right);
}

/*
Postorder:Left-Right-Root
*/

void traversePostorder(NodePtr curr)
{
    if (curr == NULL)
    {
        return;
    }
    traversePostorder(curr->left);
    traversePostorder(curr->right);
    printf("%d \n", curr->key);
}

NodePtr removeNode(NodePtr curr, int val)
{
    if (curr == NULL)
        return NULL;
    if (curr->key > val)
    {
        curr->left = removeNode(curr->left, val);
    }
    else if (curr->key < val)
    {
        curr->right = removeNode(curr->right, val);
    }
    else
    {
        if (curr->left == NULL && curr->right == NULL)
        {
            free(curr);
            return NULL;
        }
        else if (curr->left == NULL)
        {
            NodePtr temp = curr->right;
            free(curr);
            return temp;
        }
    }
}

int main()
{
    NodePtr curr = NULL;

    //printf("curr is %s", curr);
    insert(&curr, 15);
    insert(&curr, 10);
    insert(&curr, 8);
    insert(&curr, 12);
    insert(&curr, 20);
    insert(&curr, 16);
    insert(&curr, 25);
    traverseInorder(curr);
    free(curr);
    return 0;
}
