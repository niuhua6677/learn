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
		case'1'://����������
			createemptylist(&head);
			system("pause");
			break;
		case'2'://����ڵ�
			cout << "����������:" << endl;
			cin >> num;
			insert(&head, num);
			system("pause");
			break;
		case'3'://չʾ��������(����)
			putalllist(&head);
			system("pause");
			break;
		case'4'://ɾ���ڵ�
			cout << "��������Ҫɾ���Ľڵ�����:" << endl;
			cin >> num;
			deletelist(&head, num);
			system("pause");
			break;
		case'5'://�����м�ڵ�
			if (findmid(head) != NULL)
				cout << "�����м䴢���ֵΪ:" << findmid(head)->date << endl;
			system("pause");
			break;
		case'6'://�ж������Ƿ�ɻ�
			if (islooplist(head))
				cout << "true" << endl;
			else
				cout << "false" << endl;
			system("pause");
			break;
		case'7'://��ת����
			reverselist(&head);
			system("pause");
			break;
		case'8':// ������ż����
			exchange(&head);
			system("pause");
			break;
		case'9': //�˳�
			return 0;
		default:
			cout << "������Ĳ�������,����������" << endl;
			system("pause");
			break;
		}

	}
	return 0;
}