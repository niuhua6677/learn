#include "Dblist.h"
void showmenu() {
    cout << "=====欢迎进入双链表ADT=====" << endl;
    cout << "请输入您的操作" << endl;
    cout << "1.创建链表" << endl;
    cout << "2.在某位置插入节点" << endl;
    cout << "3.展示整个链表(遍历)" << endl;
    cout << "4.删除某个位置节点" << endl;
    cout << "5.查找中间节点" << endl;
    cout << "6.反转链表" << endl;
    cout << "7.查找元素位置" << endl;
    cout << "8.退出" << endl;
}
//双链表的建立，采用尾插法建立双链表(这里只创了一个头节点和一个普通节点)--->方法二
DLinkList DLinkListCreatT()
{
    Node* L, * p, * r;
    L = (Node*)malloc(sizeof(Node));//申请头结点
    L->next = NULL;
    r = L;
    r->next = NULL;                          //r 为指向终端结点的指针
    int x;
    cout << "请输入数据值" << endl;
    cin >> x;
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = r->next;
        r->next = p;
        p->prior = r;
        r = p;
    r->next = NULL;
    cout << "创建成功" << endl;
    return L;
}
//双链表的查找，查找元素为x的位置
int DLinkListFind(DLinkList L, int x)
{
    DLinkList p;                //p为检索
    p = L->next;
    int i = 1;
    while (p != NULL && p->data != x)//寻找值为x的元素**注意这里循环的条件不能写反
    {                               //原因，当p == NULL 时候 p->data 会出错
        ++i;                        //  for (i = 1, p = L->next; p; p = p->next, i++) {
        //  if (p->data == x) break;}
        p = p->next;
    }

    if (p == NULL)               //如果没找到返回0
        return 0;
    else return i;              //如果找到返回i
}
//双链表的插入，在双链表中的第i个位置插入值为x的元素
DLinkList DLinkListInsert(DLinkList L, int i, int x)
{
    if (L == NULL) {
        cout << "请先创建链表" << endl;
        return NULL;
    }
    DLinkList p, s;                          //s为要插入的结点
    p = L;                         //从第一个结点位置开始查找
    int j;
    if (i <= 0) {
        cout << "输入的位置有误" << endl;
        return NULL;
    }
    for (j = 1; j < i; j++) {
        if (p->next != NULL)
            p = p->next;
        else {
            cout << "输入的位置有误" << endl;
            return NULL;
        }
    }
    s = (Node*)malloc(sizeof(struct Node));
    s->data = x;                         //将x赋值到s的数据域
    s->next = p->next; 
    //将结点插入
    if (p->next != NULL) {
        p->next->prior = s;   //插入非尾部
        s->prior = p;
        p->next = s;
    }          //这里要区别插入的位置
    else {
        s->prior = p;     //插入尾部
        p->next = s;      
    }
    cout << "插入成功" << endl;
    return L;

}
//双链表的删除，删除双链表中第i个结点
void DLinkListDelete(DLinkList L, int i)
{
    int tempi = 1;
    DLinkList p;                        //p为查找结点。
    p = L->next;
    while ((tempi++) != i && p != NULL)
    {
        p = p->next;
    }
    if (p == NULL)                       //检查是不是在双链表中的位置
        printf("位置不合法。\n");
    else if (p->next == NULL)         //最后一个结点特殊处理，原因最后一个结点p->next没有prior
    {
        p->prior->next = NULL;
        free(p);
    }
    else                                //进行删除操作
    {
        p->prior->next = p->next;
        p->next->prior = p->prior;
        free(p);
    }
}
//判断链表是否为空(在获取链表长度时用到)
int IsEmptyDbLinkList(DLinkList pHead)
{
    DLinkList pt = pHead->next;

    if (pt == NULL)
        return 1;
    else
        return 0;
}
//遍历链表
void TraverseDbLinkList(DLinkList pHead)
{
    if (IsEmptyDbLinkList(pHead))
    {
        printf("链表为空！\n");
    }
    else
    {
        DLinkList p = (DLinkList)malloc(sizeof(struct Node));
        p = pHead->next;
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
//获得链表长度--->可用来查找中间节点--->方法二
int GetLengthDbLinkList(DLinkList pHead)
{
    int i = 0;//计数
    DLinkList p = (DLinkList)malloc(sizeof(Node));
    p = pHead->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}
//链表反转
void Reverse(DLinkList L)
{
    DLinkList p = L->next;
    DLinkList q;
    L->next = NULL;
    while (p != NULL)
    {
        q = p->next;    //基本反转操作
        p->next = L->next;
        p->prior = q;
        L->next = p;
        p = q;
    }
    cout << "反转成功" << endl;
}
