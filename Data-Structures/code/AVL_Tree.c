#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int height(struct Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(struct Node* N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;


    x->right = y;
    y->left = T2;


    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;


    y->left = x;
    x->right = T2;

  
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));

    int balance = getBalance(node);


    if (balance > 1 && key < node->left->key) {
        printf("RR Rotation at key: %d\n", node->key);
        return rightRotate(node);
    }

   
    if (balance > 1 && key > node->left->key) {
        printf("LR Rotation at key: %d\n", node->key);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

  
    if (balance < -1 && key > node->right->key) {
        printf("LL Rotation at key: %d\n", node->key);
        return leftRotate(node);
    }

   
    if (balance < -1 && key < node->right->key) {
        printf("RL Rotation at key: %d\n", node->key);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d (Balance Factor: %d) ", root->key, getBalance(root));
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printf("Enter 1 to insert a node, 2 to display in-order traversal, 3 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
        } else if (choice == 2) {
            printf("In-order traversal of the AVL tree: ");
            inOrder(root);
            printf("\n");
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
