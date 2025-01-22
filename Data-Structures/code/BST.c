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

Node* getSuccessor(Node* root) {
    root = root->right;
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
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
        // No child or only right child.
        if(root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        // Only left Child.
        if(root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        Node* successor = getSuccessor(root);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
        
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