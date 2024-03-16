#include "List.h";
int main() {
	list head = NULL;
	int num;
	char commond;
	while (1) {
		system("cls");
		showmenu();
		cin >> commond;
		switch (commond) {
		case'1'://创建空链表
			createemptylist(&head);
			system("pause");
			break;
		case'2'://插入节点
			cout << "请输入数据:" << endl;
			cin >> num;
			insert(&head, num);
			system("pause");
			break;
		case'3'://展示整个链表(遍历)
			putalllist(&head);
			system("pause");
			break;
		case'4'://删除节点
			cout << "请输入你要删除的节点数据:" << endl;
			cin >> num;
			deletelist(&head, num);
			system("pause");
			break;
		case'5'://查找中间节点
			if (findmid(head) != NULL)
				cout << "链表中间储存的值为:" << findmid(head)->date << endl;
			system("pause");
			break;
		case'6'://判断链表是否成环
			if (islooplist(head))
				cout << "true" << endl;
			else
				cout << "false" << endl;
			system("pause");
			break;
		case'7'://反转链表
			reverselist(&head);
			system("pause");
			break;
		case'8':// 链表奇偶调换
			exchange(&head);
			system("pause");
			break;
		case'9': //退出
			return 0;
		default:
			cout << "您输入的操作有误,请重新输入" << endl;
			system("pause");
			break;
		}

	}
	return 0;
}