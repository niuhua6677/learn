#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node//ѹջ�ͳ�ջ����ջ������(�����ջ��ָǰһ��)
{
    char val;//����
    struct node* next;//ָ��
}pnode;
typedef struct seqstack
{
    int size;//��¼ջ�Ĵ�С
    pnode* top;//ָ��ջ��Ԫ��
}phead;
phead* initstack()//����ջ
{
    phead* istack = (phead*)malloc(sizeof(phead));//Ϊͷ�ڵ����ռ�
    if (istack != NULL)//��׳���ж�
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}
int isempty(phead* istack)//�ж�ջΪ��
{
    if (istack->top == NULL)
    {
        return 1;//ջΪ��
    }
    return 0;//ջ��Ϊ��
}
pnode* top(phead* istack)//��ȡջ��Ԫ�ص����ݽڵ�
{
    if (istack->size != 0)//ջ��Ϊ��
    {
        return istack->top;//���ص���ջ�������ݽڵ������ջ����Ԫ��
    }
    return NULL;
}
pnode*pop(phead* istack)//����ջ��Ԫ��
{
    if (isempty(istack) == 0)//ջ��Ϊ��
    {
        pnode* account = istack->top;//��¼ջ�������ݽڵ�
        istack->top = istack->top->next;//ָ��ջ����һ��Ԫ��
        istack->size--;//��¼ջ�Ĵ�С
        return account;//���ص��������ݽڵ�
    }
    return NULL;
}
void push(phead* istack, char x)//ѹջ(��ջ)
{
    pnode* temp;//����ѹջ�����ݽڵ�
    temp = (pnode*)malloc(sizeof(pnode));
    temp->val = x;//���������
    temp->next = istack->top;//����ջ�������ݽڵ�
    istack->top = temp;//�䵱ջ��
    istack->size++;//��¼ջ��С�ı仯
    return;
}