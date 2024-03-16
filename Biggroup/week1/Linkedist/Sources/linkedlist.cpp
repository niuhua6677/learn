#include"List.h"
void showmenu() {
	cout << "=====欢迎进入单链表ADT=====" << endl;
	cout << "请输入您的操作" << endl;
	cout << "1.创建空链表" << endl;
	cout << "2.插入节点" << endl;
	cout << "3.展示整个链表(遍历)" << endl;
	cout << "4.删除节点" << endl;
	cout << "5.查找中间节点" << endl;
	cout << "6.判断链表是否成环" << endl;
	cout << "7.反转链表" << endl;
	cout << "8.链表奇偶调换" << endl;
	cout << "9.退出" << endl;
}
//创建空链表(只有头节点)
void createemptylist(list *head) {
	list p = (list)malloc(sizeof(struct node));
	if (p == NULL) {
		cout << "内存分配失败" << endl;
		return;
	}
	p->next = NULL;
	*head = p;
	cout << "创建成功" << endl;
}
//头插法插入--->方法一
//尾插法见双链表ADT
void insert(list *head,int t) {
	list p = (list)malloc(sizeof(struct node));
	if (p == NULL) {
		cout << "内存分配失败" << endl;
		return;
	}                      //判断是否合法
	if (*head == NULL) {
		cout << "请先创建空链表" << endl;
		return;
	}
	p->date = t;
	p->next = (*head)->next;
	(*head)->next = p;
	cout << "插入节点成功" << endl;
}
//据元素值删除节点
//据某位置删除节点见双链表ADT
void deletelist(list *head,int t) {
	list move = *head;
	list mid;
	if (move->next == NULL) {
		cout << "链表为空,无法删除" << endl;
	}
	while (move->next != NULL) {
		if (move->next->date == t) {
			mid = move->next;
			move->next = move->next->next;
			mid->next = NULL;
			cout << "删除节点成功" << endl;
			return;
		}
		move = move->next;
	}
	cout << "没有找到数据" <<endl ;
}
//遍历
void putalllist(list *head) {
	list move=*head;
	cout << "链表数据如下:" << endl;
	while (move->next != NULL) {
		cout << move->next->date << endl;
		move = move->next;
	}
}
//查找中间节点---->方法一--->快慢指针
//方法二---->求链表长度得中间节点---->见双链表ADT
list findmid(list head) {
	if (head == NULL || head->next == NULL) {
		cout << "空链表,无法查找" << endl;
		return NULL;
	}
	list slow = head, fast = head;
	while (fast != NULL && slow != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
//是否成环
bool islooplist(list head) {
	list fast = head, slow = head;
	while (fast->next != NULL && slow->next != NULL)
	{
		slow = slow->next;
		if ((fast = fast->next->next) == NULL)
			return false;
		if (fast == slow)//相遇则有环
			return true;
	}
	return false;
}
//链表反转--->迭代法
void reverselist(list* L) {
	list newHead;		//每次反转后的新头节点 
	list p1;			//前一个节点	
	list p2;			//下一个节点 
	p1 = (*L)->next;
	p2 = p1->next;
	p1->next = NULL;
	newHead = p1;
	while (p2 != NULL) {
		p1 = p2;
		p2 = p1->next;
		p1->next = newHead;
		newHead = p1;
	}
	(*L)->next = newHead;
	cout << "反转成功" << endl;
}
//链表奇偶交换
void exchange(list *head) {
	list p = (list)malloc(sizeof(struct node));
	p->next = (*head)->next;
	(*head)->next = (*head)->next->next;
	while (p->next != NULL && p->next->next != NULL)
	{
		list node1 = p->next; //奇节点
		list node2 = p->next->next;//偶节点
		p->next = node2;
		node1->next = node2->next;
		node2->next = node1;
		p = node1; //移到下一节点,进行下一次操作
	}
	cout << "调换成功" << endl;
	return ;
}
