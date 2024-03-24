#include <stdio.h>
#include <stdlib.h>

// ����һ��ͨ�����͵�ָ��
typedef void* GenericType;

// ��������ڵ�ṹ��
typedef struct QueueNode {
    GenericType data;
    struct QueueNode* next;
} QueueNode;

// ������ʽ���нṹ��
typedef struct LinkedQueue {
    QueueNode* front; // ��ͷָ��
    QueueNode* rear;  // ��βָ��
} LinkedQueue;

// ����һ���µ���ʽ����
LinkedQueue* createQueue() {
    LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(LinkedQueue* queue) {
    return queue->front == NULL;
}

// �ڶ�β������Ԫ��
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

// �Ӷ�ͷ�Ƴ�������Ԫ��
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
        queue->rear = NULL; // �������ֻʣһ��Ԫ�أ����¶�βָ��ΪNULL
    }

    return item;
}

// ������������
void destroyQueue(LinkedQueue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// ������һ������������ӡ��������
void printData(GenericType data) {
    // ����ֻ��һ��ռλ����ʵ��Ӧ�����������ͽ��д���
    printf("Data: %p\n", data);
}

// ʾ���÷�
int main() {
    LinkedQueue* q = createQueue();

    enqueue(q, (GenericType)"Hello");  // �������Ǵ����ַ���
    enqueue(q, (GenericType)123);     // �������Ǵ�������

    printData(dequeue(q)); // ��ӡ���Ƴ���ͷԪ��
    printData(dequeue(q)); // ��ӡ���Ƴ���һ����ͷԪ��

    destroyQueue(q);

    return 0;
}