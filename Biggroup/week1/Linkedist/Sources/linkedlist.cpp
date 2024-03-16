#include"List.h"
void showmenu() {
	cout << "=====��ӭ���뵥����ADT=====" << endl;
	cout << "���������Ĳ���" << endl;
	cout << "1.����������" << endl;
	cout << "2.����ڵ�" << endl;
	cout << "3.չʾ��������(����)" << endl;
	cout << "4.ɾ���ڵ�" << endl;
	cout << "5.�����м�ڵ�" << endl;
	cout << "6.�ж������Ƿ�ɻ�" << endl;
	cout << "7.��ת����" << endl;
	cout << "8.������ż����" << endl;
	cout << "9.�˳�" << endl;
}
//����������(ֻ��ͷ�ڵ�)
void createemptylist(list *head) {
	list p = (list)malloc(sizeof(struct node));
	if (p == NULL) {
		cout << "�ڴ����ʧ��" << endl;
		return;
	}
	p->next = NULL;
	*head = p;
	cout << "�����ɹ�" << endl;
}
//ͷ�巨����--->����һ
//β�巨��˫����ADT
void insert(list *head,int t) {
	list p = (list)malloc(sizeof(struct node));
	if (p == NULL) {
		cout << "�ڴ����ʧ��" << endl;
		return;
	}                      //�ж��Ƿ�Ϸ�
	if (*head == NULL) {
		cout << "���ȴ���������" << endl;
		return;
	}
	p->date = t;
	p->next = (*head)->next;
	(*head)->next = p;
	cout << "����ڵ�ɹ�" << endl;
}
//��Ԫ��ֵɾ���ڵ�
//��ĳλ��ɾ���ڵ��˫����ADT
void deletelist(list *head,int t) {
	list move = *head;
	list mid;
	if (move->next == NULL) {
		cout << "����Ϊ��,�޷�ɾ��" << endl;
	}
	while (move->next != NULL) {
		if (move->next->date == t) {
			mid = move->next;
			move->next = move->next->next;
			mid->next = NULL;
			cout << "ɾ���ڵ�ɹ�" << endl;
			return;
		}
		move = move->next;
	}
	cout << "û���ҵ�����" <<endl ;
}
//����
void putalllist(list *head) {
	list move=*head;
	cout << "������������:" << endl;
	while (move->next != NULL) {
		cout << move->next->date << endl;
		move = move->next;
	}
}
//�����м�ڵ�---->����һ--->����ָ��
//������---->�������ȵ��м�ڵ�---->��˫����ADT
list findmid(list head) {
	if (head == NULL || head->next == NULL) {
		cout << "������,�޷�����" << endl;
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
//�Ƿ�ɻ�
bool islooplist(list head) {
	list fast = head, slow = head;
	while (fast->next != NULL && slow->next != NULL)
	{
		slow = slow->next;
		if ((fast = fast->next->next) == NULL)
			return false;
		if (fast == slow)//�������л�
			return true;
	}
	return false;
}
//����ת--->������
void reverselist(list* L) {
	list newHead;		//ÿ�η�ת�����ͷ�ڵ� 
	list p1;			//ǰһ���ڵ�	
	list p2;			//��һ���ڵ� 
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
	cout << "��ת�ɹ�" << endl;
}
//������ż����
void exchange(list *head) {
	list p = (list)malloc(sizeof(struct node));
	p->next = (*head)->next;
	(*head)->next = (*head)->next->next;
	while (p->next != NULL && p->next->next != NULL)
	{
		list node1 = p->next; //��ڵ�
		list node2 = p->next->next;//ż�ڵ�
		p->next = node2;
		node1->next = node2->next;
		node2->next = node1;
		p = node1; //�Ƶ���һ�ڵ�,������һ�β���
	}
	cout << "�����ɹ�" << endl;
	return ;
}
