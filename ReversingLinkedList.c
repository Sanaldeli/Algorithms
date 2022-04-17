#include <stdio.h>
#include <stdlib.h>

// Reversing the linked list using a data structure (I chose stack)

#define MAX 50

typedef struct
{
    int top;
    int arr[MAX];
} STACK;

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct
{
    int value;
    short errorFlag;
} result;

STACK s;
node *head;

void reverseList();

// Stack functions
void initStack();
int isEmpty();
int isFull();
int push(int value);
result pop();
result peek();

// Linked list functions
void newNode(int value);
void printList();
void freeList();

int main()
{
    int i;

    initStack();

    newNode(5);
    newNode(16);
    newNode(22);
    newNode(3);
    newNode(99);
    newNode(101);
    newNode(20);
    newNode(36);
    newNode(27);
    newNode(40);

    printList();

    reverseList();

    printList();

    freeList();

    return 0;
}

void reverseList()
{
    node *temp = head;
    result res;

    while (temp != NULL)
    {
        push(temp->value);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        res = pop();
        if (res.errorFlag)
        {
            printf("Stack underflow\n");
            return;
        }
        temp->value = res.value;
        temp = temp->next;
    }
}

void initStack()
{
    s.top = -1;
}

int isEmpty()
{
    if (s.top == -1)
        return 1;

    return 0;
}

int isFull()
{
    if (s.top == MAX - 1)
        return 1;

    return 0;
}

int push(int value)
{
    if (isFull())
        return 1;

    s.arr[++s.top] = value;

    return 0;
}

result pop()
{
    result res;

    if (isEmpty())
    {
        res.errorFlag = 1;
        return res;
    }

    res.errorFlag = 0;
    res.value = s.arr[s.top--];

    return res;
}

result peek()
{
    result res;

    if (isEmpty())
    {
        res.errorFlag = 1;
        return res;
    }

    res.errorFlag = 0;
    res.value = s.arr[s.top];

    return res;
}

void newNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void printList()
{
    node *temp = head;
    printf("[");
    while (temp != NULL)
    {
        printf("%5d", temp->value);
        if (temp->next != NULL)
            printf(", ");

        temp = temp->next;
    }
    printf("]\n");
}

void freeList()
{
    node *temp;
    while (temp != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    printf("Deallocation successful!\n");
}