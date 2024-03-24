#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
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
phead* initstack();
int isempty(phead* istack);
pnode* seqstack_top(phead* istack);
pnode* pop(phead* istack);
void push(phead* istack, char x);
void char_put(char ch);
int priority(char ch);
int is_number(char ch);
int is_operator(char ch);
int is_left(char ch);
int is_right(char ch);
int transform(char str[]);
//�·�Ϊ�����׺���ʽ��Ҫ�ĺ���
typedef struct node1//�����ջ������ջ
{
    int val;//����
    struct node1* next;//ָ��
}pnode1;
typedef struct seqstack1
{
    int size;//��¼ջ�Ĵ�С
    pnode1* top;//ָ��ջ��Ԫ��
}phead1;
phead1* initstack1();
int isempty1(phead1* istack);
int seqstack_top1(phead1* istack);
int pop1(phead1* istack);
void push1(phead1* istack, int x);
int express(int left, int right, char op);
int getsize(phead1* stack);
int calculate(char str[]);