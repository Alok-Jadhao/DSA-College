#include<stdio.h>
#include<stdlib.h>

typedef struct DoublyNode {
    int data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
} DoublyNode;

DoublyNode* createNode(int data) {
    DoublyNode *newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
}

DoublyNode* insertNode(DoublyNode *head, int data) {
    DoublyNode *newNode = createNode(data);
    DoublyNode* temp = head;
    if(head == NULL) {
        head = newNode;
        return head;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

DoublyNode* reverse(DoublyNode *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    DoublyNode* current = head;
    DoublyNode* previous = NULL;

    while(current != NULL) {
        previous = current->prev;
        current->prev = current->next;
        current->next = previous;

        current = current->prev;
    }

    
                                           
    if(previous != NULL) {
        head = previous->prev;
    }

    return head;
}

void displayList(DoublyNode *head) {
    DoublyNode* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    DoublyNode *head = NULL;

    while(1) {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        if(data == -1) {
            break;
        }
        head = insertNode(head, data);
    }

    head = reverse(head);
    displayList(head);
}

