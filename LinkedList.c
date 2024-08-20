#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
struct Node *createnode(int data, struct Node *next)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = next;
    return node;
}
struct Node *createNodewithNull(int data)
{
    return createnode(data, NULL);
}

int main()
{
    struct Node *node = createNodewithNull(15);
    printf("%p\n", (void *)node);
    printf("%d\n", node->data);

    free(node);
}