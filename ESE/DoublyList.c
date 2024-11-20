#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
}

Node* insertEnd(Node* head, int data) {
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    Node* newNode = createNode(data);
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

Node* concat(Node* head1, Node* head2) {
    Node* temp = head1;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;
    head2->prev = temp;

    return head1;
}

void display(Node* head) {
    Node* temp = head;
    printf("HEAD-> ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}

Node* insertPos(Node* head, int pos, int data) {
    int curr = 0;
    Node* temp = head;
    while(temp->next != NULL && curr < pos) {
        temp = temp->next;
        curr++;

    }
    Node* newNode = createNode(data);
    temp->next->prev = newNode;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

void sort(Node* head) {

}


