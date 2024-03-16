#pragma once
#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
// 定义双链表结点类型
typedef struct Node
{
    int data;
    struct Node* prior;         //指向前驱结点
    struct Node* next;          //指向后继结点
}Node, * DLinkList;
//函数声明
void showmenu();
DLinkList DLinkListCreatT();
int DLinkListFind(DLinkList L, int x);
DLinkList DLinkListInsert(DLinkList L, int i, int x);
void DLinkListDelete(DLinkList L, int i);
int IsEmptyDbLinkList(DLinkList pHead);
void TraverseDbLinkList(DLinkList pHead);
int GetLengthDbLinkList(DLinkList pHead);
void Reverse(DLinkList L);
