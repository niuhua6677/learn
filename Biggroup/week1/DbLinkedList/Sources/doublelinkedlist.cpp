#include "Dblist.h"
void showmenu() {
    cout << "=====��ӭ����˫����ADT=====" << endl;
    cout << "���������Ĳ���" << endl;
    cout << "1.��������" << endl;
    cout << "2.��ĳλ�ò���ڵ�" << endl;
    cout << "3.չʾ��������(����)" << endl;
    cout << "4.ɾ��ĳ��λ�ýڵ�" << endl;
    cout << "5.�����м�ڵ�" << endl;
    cout << "6.��ת����" << endl;
    cout << "7.����Ԫ��λ��" << endl;
    cout << "8.�˳�" << endl;
}
//˫����Ľ���������β�巨����˫����(����ֻ����һ��ͷ�ڵ��һ����ͨ�ڵ�)--->������
DLinkList DLinkListCreatT()
{
    Node* L, * p, * r;
    L = (Node*)malloc(sizeof(Node));//����ͷ���
    L->next = NULL;
    r = L;
    r->next = NULL;                          //r Ϊָ���ն˽���ָ��
    int x;
    cout << "����������ֵ" << endl;
    cin >> x;
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = r->next;
        r->next = p;
        p->prior = r;
        r = p;
    r->next = NULL;
    cout << "�����ɹ�" << endl;
    return L;
}
//˫����Ĳ��ң�����Ԫ��Ϊx��λ��
int DLinkListFind(DLinkList L, int x)
{
    DLinkList p;                //pΪ����
    p = L->next;
    int i = 1;
    while (p != NULL && p->data != x)//Ѱ��ֵΪx��Ԫ��**ע������ѭ������������д��
    {                               //ԭ�򣬵�p == NULL ʱ�� p->data �����
        ++i;                        //  for (i = 1, p = L->next; p; p = p->next, i++) {
        //  if (p->data == x) break;}
        p = p->next;
    }

    if (p == NULL)               //���û�ҵ�����0
        return 0;
    else return i;              //����ҵ�����i
}
//˫����Ĳ��룬��˫�����еĵ�i��λ�ò���ֵΪx��Ԫ��
DLinkList DLinkListInsert(DLinkList L, int i, int x)
{
    if (L == NULL) {
        cout << "���ȴ�������" << endl;
        return NULL;
    }
    DLinkList p, s;                          //sΪҪ����Ľ��
    p = L;                         //�ӵ�һ�����λ�ÿ�ʼ����
    int j;
    if (i <= 0) {
        cout << "�����λ������" << endl;
        return NULL;
    }
    for (j = 1; j < i; j++) {
        if (p->next != NULL)
            p = p->next;
        else {
            cout << "�����λ������" << endl;
            return NULL;
        }
    }
    s = (Node*)malloc(sizeof(struct Node));
    s->data = x;                         //��x��ֵ��s��������
    s->next = p->next; 
    //��������
    if (p->next != NULL) {
        p->next->prior = s;   //�����β��
        s->prior = p;
        p->next = s;
    }          //����Ҫ��������λ��
    else {
        s->prior = p;     //����β��
        p->next = s;      
    }
    cout << "����ɹ�" << endl;
    return L;

}
//˫�����ɾ����ɾ��˫�����е�i�����
void DLinkListDelete(DLinkList L, int i)
{
    int tempi = 1;
    DLinkList p;                        //pΪ���ҽ�㡣
    p = L->next;
    while ((tempi++) != i && p != NULL)
    {
        p = p->next;
    }
    if (p == NULL)                       //����ǲ�����˫�����е�λ��
        printf("λ�ò��Ϸ���\n");
    else if (p->next == NULL)         //���һ��������⴦��ԭ�����һ�����p->nextû��prior
    {
        p->prior->next = NULL;
        free(p);
    }
    else                                //����ɾ������
    {
        p->prior->next = p->next;
        p->next->prior = p->prior;
        free(p);
    }
}
//�ж������Ƿ�Ϊ��(�ڻ�ȡ������ʱ�õ�)
int IsEmptyDbLinkList(DLinkList pHead)
{
    DLinkList pt = pHead->next;

    if (pt == NULL)
        return 1;
    else
        return 0;
}
//��������
void TraverseDbLinkList(DLinkList pHead)
{
    if (IsEmptyDbLinkList(pHead))
    {
        printf("����Ϊ�գ�\n");
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
//���������--->�����������м�ڵ�--->������
int GetLengthDbLinkList(DLinkList pHead)
{
    int i = 0;//����
    DLinkList p = (DLinkList)malloc(sizeof(Node));
    p = pHead->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}
//����ת
void Reverse(DLinkList L)
{
    DLinkList p = L->next;
    DLinkList q;
    L->next = NULL;
    while (p != NULL)
    {
        q = p->next;    //������ת����
        p->next = L->next;
        p->prior = q;
        L->next = p;
        p = q;
    }
    cout << "��ת�ɹ�" << endl;
}
