#pragma once
#include<iostream>
#include<cstdio>
using namespace std;
typedef struct node* list;
//节点定义
struct node {
	int date;
	list next;
};
//函数声明
void showmenu();
void createemptylist(list* head);
void insert(list* head, int t);
void deletelist(list* head, int t);
void putalllist(list* head);
list findmid(list head);
bool islooplist(list head);
void reverselist(list* L);
void exchange(list* head);