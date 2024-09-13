#include<stdio.h>
#include<stdlib.h>

//Construct ,Insert, Delete, Traverse

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(Node* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// void deleteNode(Node* root, int data) {
//     if(root == NULL) {
//         return;
//     }
//     if(data < root->data) {
//         deleteNode(root->left, data);
//     } else {
//         deleteNode(root->right, data);
//     }
// }

Node* deleteNode(Node* root, int data) {
    if(root == NULL) {
        return root;
    }

    
}

// struct Node* delNode(struct Node* root, int x) {

//     // Base case
//     if (root == NULL)
//         return root;

//     // If key to be searched is in a subtree
//     if (root->key > x)
//         root->left = delNode(root->left, x);
//     else if (root->key < x)
//         root->right = delNode(root->right, x);
//     else {
//         // If root matches with the given key

//         // Cases when root has 0 children or 
//         // only right child
//         if (root->left == NULL) {
//             struct Node* temp = root->right;
//             free(root);
//             return temp;
//         }

//         // When root has only left child
//         if (root->right == NULL) {
//             struct Node* temp = root->left;
//             free(root);
//             return temp;
//         }

//         // When both children are present
//         struct Node* succ = getSuccessor(root);
//         root->key = succ->key;
//         root->right = delNode(root->right, succ->key);
//     }
//     return root;
// }




