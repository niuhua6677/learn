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
        case'1'://创建链表
            head = DLinkListCreatT();
            system("pause");
            break;
        case'2'://插入节点
            cout << "请输入你要插入的位置与数据值:" << endl;
            cin >> num >> x;
            DLinkListInsert(head, num, x);
            system("pause");
            break;
        case'3'://展示整个链表(遍历)
            TraverseDbLinkList(head);
            system("pause");
            break;
        case'4'://删除节点
            cout << "请输入你要删除的节点位置:" << endl;
            cin >> num;
            DLinkListDelete(head, num);
            system("pause");
            break;
        case'5'://查找中间节点
            int i;
            for (i = 1; i <= (GetLengthDbLinkList(head) + 1) / 2; i++) {
                move = move->next;
            }
            cout << "链表中间储存的值为:" << move->data << endl;
            system("pause");
            break;
        case'6'://反转链表
            Reverse(head);
            system("pause");
            break;
        case'7'://查找元素位置
            cout << "请输入你要查找的数据值" << endl;
            cin >> num;
            if (DLinkListFind(head, num) == 0)
                cout << "没有找到数据" << endl;
            cout << "在链表的位置为:" << DLinkListFind(head, num) << endl;
            system("pause");
            break;
        case'8': //退出
            return 0;
        default:
            cout << "您输入的操作有误,请重新输入" << endl;
            system("pause");
            break;
        }
    }
    return 0;

}