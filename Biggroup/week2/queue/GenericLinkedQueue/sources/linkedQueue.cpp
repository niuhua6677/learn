#include <stdio.h>
#include <stdlib.h>

// 定义一个通用类型的指针
typedef void* GenericType;

// 定义链表节点结构体
typedef struct QueueNode {
    GenericType data;
    struct QueueNode* next;
} QueueNode;

// 定义链式队列结构体
typedef struct LinkedQueue {
    QueueNode* front; // 队头指针
    QueueNode* rear;  // 队尾指针
} LinkedQueue;

// 创建一个新的链式队列
LinkedQueue* createQueue() {
    LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

// 判断队列是否为空
int isEmpty(LinkedQueue* queue) {
    return queue->front == NULL;
}

// 在队尾插入新元素
void enqueue(LinkedQueue* queue, GenericType item) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = item;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 从队头移除并返回元素
GenericType dequeue(LinkedQueue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Dequeue from empty queue.\n");
        exit(EXIT_FAILURE);
    }

    QueueNode* temp = queue->front;
    GenericType item = temp->data;

    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL; // 如果队列只剩一个元素，更新队尾指针为NULL
    }

    return item;
}

// 清理整个队列
void destroyQueue(LinkedQueue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// 假设有一个函数用来打印或处理数据
void printData(GenericType data) {
    // 这里只是一个占位符，实际应根据数据类型进行处理
    printf("Data: %p\n", data);
}

// 示例用法
int main() {
    LinkedQueue* q = createQueue();

    enqueue(q, (GenericType)"Hello");  // 假设我们存入字符串
    enqueue(q, (GenericType)123);     // 假设我们存入整数

    printData(dequeue(q)); // 打印并移除队头元素
    printData(dequeue(q)); // 打印并移除下一个队头元素

    destroyQueue(q);

    return 0;
}