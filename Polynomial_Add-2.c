#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node *createNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

Node *insertNode(Node *head, int coeff, int exp)
{
    Node *newNode = createNode(coeff, exp);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coeff, temp->exp);
        if (temp->next != NULL)
        {
            printf("+ ");
        }
        temp = temp->next;
    }
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *temp1 = poly1;
    Node *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp > temp2->exp)
        {
            result = insertNode(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else if (temp1->exp < temp2->exp)
        {
            result = insertNode(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
        else
        {
            int sum = temp1->coeff + temp2->coeff;
            if (sum != 0)
            {
                result = insertNode(result, sum, temp1->exp);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Add remaining terms from poly1
    while (temp1 != NULL)
    {
        result = insertNode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    // Add remaining terms from poly2
    while (temp2 != NULL)
    {
        result = insertNode(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

int main()
{
    printf("Polynomial 1: \n");
    Node *poly1 = NULL;
    printf("Enter no. of terms in P1: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int coeff, exp;
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly1 = insertNode(poly1, coeff, exp);
    }

    printf("Polynomial 2: \n");
    Node *poly2 = NULL;
    printf("Enter no. of terms in P2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int coeff, exp;
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly2 = insertNode(poly2, coeff, exp);
    }

    Node *result = addPolynomials(poly1, poly2);
    displayList(result);
}