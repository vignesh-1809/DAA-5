#include <stdio.h>
#include <stdlib.h>
struct StackNode {
    int data;
    struct StackNode* next;
};
struct Stack {
    struct StackNode* top;
};
struct StackNode* createStackNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isStackEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }

    struct StackNode* topNode = stack->top;
    int data = topNode->data;
    stack->top = topNode->next;

    free(topNode);
    return data;
}
struct Queue {
    struct Stack* mainStack;
    struct Stack* auxStack;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->mainStack = createStack();
    queue->auxStack = createStack();
    return queue;
}

void enqueue(struct Queue* queue, int data) {

    while (!isStackEmpty(queue->mainStack)) {
        push(queue->auxStack, pop(queue->mainStack));
    }


    push(queue->mainStack, data);

    while (!isStackEmpty(queue->auxStack)) {
        push(queue->mainStack, pop(queue->auxStack));
    }
}

int dequeue(struct Queue* queue) {
    return pop(queue->mainStack);
}

int main() {
    struct Queue* queue = createQueue();
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        enqueue(queue, a);
    }

    printf("Dequeued element: %d\n", dequeue(queue));


    return 0;
}
