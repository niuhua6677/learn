#include "Dblist.h"
int main() {
    DLinkList head = NULL;
    int num, x;
    char commond;
    while (1) {
        system("cls");
        showmenu();
        DLinkList move = head;
        cin >> commond;
        switch (commond) {
        case'1'://��������
            head = DLinkListCreatT();
            system("pause");
            break;
        case'2'://����ڵ�
            cout << "��������Ҫ�����λ��������ֵ:" << endl;
            cin >> num >> x;
            DLinkListInsert(head, num, x);
            system("pause");
            break;
        case'3'://չʾ��������(����)
            TraverseDbLinkList(head);
            system("pause");
            break;
        case'4'://ɾ���ڵ�
            cout << "��������Ҫɾ���Ľڵ�λ��:" << endl;
            cin >> num;
            DLinkListDelete(head, num);
            system("pause");
            break;
        case'5'://�����м�ڵ�
            int i;
            for (i = 1; i <= (GetLengthDbLinkList(head) + 1) / 2; i++) {
                move = move->next;
            }
            cout << "�����м䴢���ֵΪ:" << move->data << endl;
            system("pause");
            break;
        case'6'://��ת����
            Reverse(head);
            system("pause");
            break;
        case'7'://����Ԫ��λ��
            cout << "��������Ҫ���ҵ�����ֵ" << endl;
            cin >> num;
            if (DLinkListFind(head, num) == 0)
                cout << "û���ҵ�����" << endl;
            cout << "�������λ��Ϊ:" << DLinkListFind(head, num) << endl;
            system("pause");
            break;
        case'8': //�˳�
            return 0;
        default:
            cout << "������Ĳ�������,����������" << endl;
            system("pause");
            break;
        }
    }
    return 0;

}