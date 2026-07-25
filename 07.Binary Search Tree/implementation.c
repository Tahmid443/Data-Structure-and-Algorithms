#include <stdio.h>
#include <stdlib.h>

//=====================
// Tree Node Structure
//=====================
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

//=====================
// Create Node
//=====================
struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//=====================
// Preorder Traversal
// Root -> Left -> Right
//=====================
void preorder(struct Node *root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}

//=====================
// Inorder Traversal
// Left -> Root -> Right
//=====================
void inorder(struct Node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

//=====================
// Postorder Traversal
// Left -> Right -> Root
//=====================
void postorder(struct Node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    printf("%d ", root->data);
}

//=====================
// Count Total Nodes
//=====================
int countNodes(struct Node *root)
{
    if(root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

//=====================
// Count Leaf Nodes
//=====================
int countLeaf(struct Node *root)
{
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

//=====================
// Height of Tree
//=====================
int height(struct Node *root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

//=====================
// Search
//=====================
int search(struct Node *root, int key)
{
    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;

    return search(root->left, key) || search(root->right, key);
}

//=====================
// Main Function
//=====================
int main()
{
    struct Node *root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    root->right->left = createNode(60);
    root->right->right = createNode(70);

    printf("Preorder : ");
    preorder(root);

    printf("\nInorder : ");
    inorder(root);

    printf("\nPostorder : ");
    postorder(root);

    printf("\n\nTotal Nodes = %d", countNodes(root));

    printf("\nLeaf Nodes = %d", countLeaf(root));

    printf("\nHeight = %d", height(root));

    if(search(root, 60))
        printf("\n60 Found");
    else
        printf("\n60 Not Found");
    
    return 0;
}