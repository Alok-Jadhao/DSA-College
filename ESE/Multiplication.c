#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coefficient;
    int exponent;
    struct PolyNode* next;
} PolyNode;

// Function to create a new polynomial node
PolyNode* createPolyNode(int coefficient, int exponent) {
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to multiply two polynomials
PolyNode* multiplyPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;

    for (PolyNode* ptr1 = poly1; ptr1; ptr1 = ptr1->next) {
        for (PolyNode* ptr2 = poly2; ptr2; ptr2 = ptr2->next) {
            int coeff = ptr1->coefficient * ptr2->coefficient;
            int exp = ptr1->exponent + ptr2->exponent;

            PolyNode** temp = &result;
            while (*temp && (*temp)->exponent > exp) {
                temp = &((*temp)->next);
            }

            if (*temp && (*temp)->exponent == exp) {
                (*temp)->coefficient += coeff;
            } else {
                PolyNode* newNode = createPolyNode(coeff, exp);
                newNode->next = *temp;
                *temp = newNode;
            }
        }
    }
    return result;
}

// Helper function to display polynomial
void displayPolynomial(PolyNode* poly) {
    while (poly) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly) printf(" + ");
    }
    printf("\n");
}

int main() {
    PolyNode* poly1 = createPolyNode(3, 3);
    poly1->next = createPolyNode(4, 2);
    poly1->next->next = createPolyNode(2, 0);

    PolyNode* poly2 = createPolyNode(1, 2);
    poly2->next = createPolyNode(2, 1);
    poly2->next->next = createPolyNode(3, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    PolyNode* result = multiplyPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}

