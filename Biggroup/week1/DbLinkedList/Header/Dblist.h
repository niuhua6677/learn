#pragma once
#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
// ����˫����������
typedef struct Node
{
    int data;
    struct Node* prior;         //ָ��ǰ�����
    struct Node* next;          //ָ���̽��
}Node, * DLinkList;
//��������
void showmenu();
DLinkList DLinkListCreatT();
int DLinkListFind(DLinkList L, int x);
DLinkList DLinkListInsert(DLinkList L, int i, int x);
void DLinkListDelete(DLinkList L, int i);
int IsEmptyDbLinkList(DLinkList pHead);
void TraverseDbLinkList(DLinkList pHead);
int GetLengthDbLinkList(DLinkList pHead);
void Reverse(DLinkList L);
