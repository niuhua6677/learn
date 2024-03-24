#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
typedef struct node//压栈和出栈都在栈顶进行(这里的栈顶指前一段)
{
    char val;//数据
    struct node* next;//指针
}pnode;
typedef struct seqstack
{
    int size;//记录栈的大小
    pnode* top;//指向栈顶元素
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
//下方为计算后缀表达式需要的函数
typedef struct node1//这里的栈是整型栈
{
    int val;//数据
    struct node1* next;//指针
}pnode1;
typedef struct seqstack1
{
    int size;//记录栈的大小
    pnode1* top;//指向栈顶元素
}phead1;
phead1* initstack1();
int isempty1(phead1* istack);
int seqstack_top1(phead1* istack);
int pop1(phead1* istack);
void push1(phead1* istack, int x);
int express(int left, int right, char op);
int getsize(phead1* stack);
int calculate(char str[]);