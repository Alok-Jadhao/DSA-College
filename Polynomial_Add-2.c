#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node *createNode(int coeff, int exp) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node *head, int coeff, int exp) {
    Node *newNode = createNode(coeff, exp);
    if(head == NULL) {
        head = newNode; 
        return head;
    }
    Node *temp = head; 
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displayList(Node *head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if(temp->next != NULL) {
            printf("+ ");
        }
        temp = temp->next;
    }
}


Node* inputPoly() {
    Node *head = NULL;
    int coeff, exp;
    printf("Enter the polynomial in the form of ax^b (e.g., 5x^2 + 6x^1): ");
    while(1) {
        scanf("%dx^%d", &coeff, &exp);
        head = insertNode(head, coeff, exp);
        char ch = getchar();
        if(ch == '\n') {
            break;
        }
    }
    return head;
}

Node* addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;
    Node *temp1 = poly1;
    Node *temp2 = poly2;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->exp > temp2->exp) {
            result = insertNode(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp < temp2->exp) {
            result = insertNode(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else {
            int sum = temp1->coeff + temp2->coeff;
            if(sum != 0) {
                result = insertNode(result, sum, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL) {
        result = insertNode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while(temp2 != NULL) {
        result = insertNode(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}



int main() {
    printf("Polynomial 1: \n");
    Node* poly1 = inputPoly();
    printf("Polynomial 2: \n");
    Node* poly2 = inputPoly();

    Node* result = addPolynomials(poly1, poly2);
    displayList(result);
    
}