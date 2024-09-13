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

void preorderTraversal(Node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if(root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}


// Delete leaf and parent with one child.
Node* deleteNode(Node* root, int data) {
    if(root == NULL) {
        return root;
    }

    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if(root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        if(root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
    }
    return root;
    
}


int main() {
    Node* root = NULL;
    //user input
    int n;
    int data;
    
    while(1) {
        printf("1. Insert  2. Delete  3. Traverse  4. Exit\n");
        scanf("%d", &n);

        switch(n) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                if(data != -1) {
                    root = insertNode(root, data);    
                }
                
                break;

            case 2:
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                deleteNode(root, data);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            default:
                printf("Invalid Input\n");
                break;
        }
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
