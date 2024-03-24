#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
phead* initstack()//创建栈
{
    phead* istack = (phead*)malloc(sizeof(phead));//为头节点分配空间
    if (istack != NULL)//健壮性判断
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}
int isempty(phead* istack)//判断栈为空
{
    if (istack->top == NULL)
    {
        return 1;//栈为空
    }
    return 0;//栈不为空
}
pnode* top(phead* istack)//获取栈顶元素的数据节点
{
    if (istack->size != 0)//栈不为空
    {
        return istack->top;//返回的是栈顶的数据节点而不是栈顶的元素
    }
    return NULL;
}
pnode*pop(phead* istack)//弹出栈顶元素
{
    if (isempty(istack) == 0)//栈不为空
    {
        pnode* account = istack->top;//记录栈顶的数据节点
        istack->top = istack->top->next;//指向栈顶下一个元素
        istack->size--;//记录栈的大小
        return account;//返回弹出的数据节点
    }
    return NULL;
}
void push(phead* istack, char x)//压栈(入栈)
{
    pnode* temp;//进行压栈的数据节点
    temp = (pnode*)malloc(sizeof(pnode));
    temp->val = x;//填充数据域
    temp->next = istack->top;//连接栈顶的数据节点
    istack->top = temp;//充当栈顶
    istack->size++;//记录栈大小的变化
    return;
}