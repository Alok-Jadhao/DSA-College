#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

Node* insertNode(Node* root, int data) {
    Node* newNode = createNode(data);
    if(root == NULL) {
        return newNode;
    }

    if(root->data > data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    printf("Inorder Traversal: ");
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if(root == NULL) {
        return;
    }

    printf("Preorder Traversal: ");
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }

    printf("Postorder Traversal: ");
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int getHeight(Node* node) {
    if(node == NULL) return -1;

    int leftHeight = getHeight(node->left);  // Height of left subtree
    int rightHeight = getHeight(node->right); // Height of right subtree

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);

}

Node* predecessor(Node* node) {
    if(node == NULL) return NULL;

    Node* temp = node->left;
    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}

Node* succecessor(Node* node) {
    if(node == NULL) return NULL;

    Node* temp = node->right;
    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

int getBalancef(Node* node) {
    int right = getHeight(node->right);
    int left = getHeight(node->left);

    return left - right;
}

int leaves(Node* root) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) {
        return 1;
    }

    return leaves(root->right) + leaves(root->left);
}

int findMin(Node* root) {
    if(root == NULL) {
        printf("Tree emply");
        return -1;
    }

    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}

int findMax(Node* root) {
    if(root == NULL) {
        printf("Tree emply");
        return -1;
    }

    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}

int main() {
    printf("hello");

    return 0;
}