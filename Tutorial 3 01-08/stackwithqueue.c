#include <stdio.h>
#include <stdlib.h>
struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct QueueNode* frontNode = queue->front;
    int data = frontNode->data;
    queue->front = frontNode->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(frontNode);
    return data;
}

struct Stack {
    struct Queue* mainQueue;
    struct Queue* auxQueue;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->mainQueue = createQueue();
    stack->auxQueue = createQueue();
    return stack;
}

void push(struct Stack* stack, int data) {
    enqueue(stack->mainQueue, data);
}


int pop(struct Stack* stack) {
    if (isQueueEmpty(stack->mainQueue)) {
        printf("Stack is empty.\n");
        return -1;
    }

    while (stack->mainQueue->front->next != NULL) {
        enqueue(stack->auxQueue, dequeue(stack->mainQueue));
    }

    int topElement = dequeue(stack->mainQueue);

    struct Queue* temp = stack->mainQueue;
    stack->mainQueue = stack->auxQueue;
    stack->auxQueue = temp;

    return topElement;
}

int main() {
    struct Stack* stack = createStack();
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        push(stack, a);
    }



    printf("Popped element: %d\n", pop(stack));


    return 0;
}
