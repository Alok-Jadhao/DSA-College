#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}


Node* insertNode(Node *head, int coeff, int exp) {
    if (head == NULL) {
        return createNode(coeff, exp);
    }

    Node *temp = head;
    Node *prev = NULL;


    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }


    if (temp != NULL && temp->exp == exp) {

        temp->coeff += coeff;
        if (temp->coeff == 0) {
     
            if (prev != NULL) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
        }
    } else {

        Node *newNode = createNode(coeff, exp);
        if (prev == NULL) {
            newNode->next = head;
            head = newNode;
        } else {
            prev->next = newNode;
            newNode->next = temp;
        }
    }
    return head;
}

// Function to display the polynomial
void displayList(Node *head) {
    Node* temp = head;
    while(temp != NULL) {
        if (temp->coeff != 0) {
            if (temp != head && temp->coeff > 0) {
                printf(" + ");
            }
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to read and input a polynomial
Node* inputPoly() {
    Node *head = NULL;
    int coeff, exp;
    printf("Enter the polynomial in the form of ax^b (e.g., 5x^2 + 6x^1): ");
    while (1) {
        if (scanf("%dx^%d", &coeff, &exp) == 2) {
            head = insertNode(head, coeff, exp);
        }
        char ch = getchar();
        if (ch == '\n') {
            break;
        }
    }
    return head;
}

// Function to add two polynomials
Node* addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;
    Node *temp1 = poly1;
    Node *temp2 = poly2;

    // Insert all nodes from the first polynomial into the result
    while (temp1 != NULL) {
        result = insertNode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    // Insert all nodes from the second polynomial into the result
    while (temp2 != NULL) {
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
    printf("Result:\n");
    displayList(result);

    // Free memory (not shown here for brevity)
    return 0;
}
