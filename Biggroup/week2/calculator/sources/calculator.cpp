#include"calculate.h"
phead* initstack()//����ջ
{
    phead* istack = (phead*)malloc(sizeof(phead));//Ϊͷ�ڵ����ռ�
    if (istack != NULL)//��׳���ж�
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}
int isempty(phead* istack)//�ж�ջΪ��
{
    if (istack->top == NULL)
    {
        return 1;//ջΪ��
    }
    return 0;//ջ��Ϊ��
}
pnode* seqstack_top(phead* istack)//��ȡջ��Ԫ�ص����ݽڵ�
{
    if (istack->size != 0)//ջ����
        return istack->top;//���ص���ջ�������ݽڵ������ջ����Ԫ��
    return NULL;
}
pnode* pop(phead* istack)//����ջ��Ԫ��
{
    if (isempty(istack) == 0)
    {
        pnode* account = istack->top;//��¼ջ�������ݽڵ�
        istack->top = istack->top->next;//ָ��ջ����һ��Ԫ��
        istack->size--;//��¼ջ�Ĵ�С
        return account;//���ص��������ݽڵ�
    }
    return NULL;
}
void push(phead* istack, char x)//ѹջ(��ջ)
{
    pnode* temp;//����ѹջ�����ݽڵ�
    temp = (pnode*)malloc(sizeof(pnode));
    temp->val = x;//���������
    temp->next = istack->top;//����ջ�������ݽڵ�
    istack->top = temp;//�䵱ջ��
    istack->size++;//��¼ջ��С�ı仯
    return;
}
char buffer[256] = {0};//�����
//��������׺���ʽת��׺���ʽ�ĺ���
int index = 0;
void char_put(char ch)//�������ַ������������
{
    buffer[index++] = ch;
}
int priority(char ch)//�����Ƚ����ȼ�
{
    int ret = 0;
    switch (ch)
    {
    case '+':
    case '-':
        ret = 1;
        break;
    case '*':
    case '/':
        ret = 2;
        break;
    default:
        break;
    }
    return ret;
}
int is_number(char ch)//�ǲ�������
{
    return(ch >= '0' && ch <= '9');//���ַ���1�����򷵻�0
}
int is_operator(char ch)//�ǲ��������
{
    return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int is_left(char ch)//�ǲ���������
{
    return(ch == '(');
}
int is_right(char ch)//�ǲ���������
{
    return(ch == ')');
}
int transform(char str[])//��������׺ת���ɺ�׺
{
    phead* istack = initstack();//����һ��ջ
    int i = 0;
    while (str[i] != '\0')//���������ַ���
    {
        //�ж��ǲ�������
        if (is_number(str[i]) == 1)
        {
            if (is_number(str[i + 1]) == 1)//����Ҳ������,��ֱ�ӷ�
                char_put(str[i]);//����ֱ�ӷ�������(�����)
            else//���治������,���һ���ո���Ϊ�ָ���
            {
                char_put(str[i]);
                char_put(' ');
            }
        }
        else if (is_operator((str[i])) == 1)
        {
            if (str[i + 1] == '0' && str[i] == '/')
            {
                printf("�Ƿ����뱻����Ϊ0\n");
                char_put('\0');
                return 0;
            }
            if (isempty(istack) == 0)//ջ��Ϊ��
            {
                while ((isempty(istack) == 0) && (priority(str[i]) <= (priority(seqstack_top(istack)->val))))//ջ��Ϊ�ղ�������������ȼ�������ջ��
                {
                    char_put(pop(istack)->val);//����������ջ���͵���ֱ������������
                    char_put(' ');
                }
            }
            push(istack, str[i]);//�ٽ����������ջ
        }
        else if (is_left(str[i]))//������ֱ����
           push(istack, str[i]);
        else if (is_right(str[i]))//�ж��ǲ���������
        {
            while (is_left(seqstack_top(istack)->val) != 1)//ջ�����������ŵ����
            {
                char_put(pop(istack)->val);
                if (isempty(istack) == 1) {
                    char_put('\0');
                    return -1;
                }
            }
            //��ʱƥ�䵽��������
            pop(istack);
            //����������
        }
        else {
            char_put('\0');
            return -1;
        }
        i++;
    }
    if (str[i] == '\0')//�ɹ��������ַ���ĩβ
    {
        while (isempty(istack) == 0)
        {
            if (seqstack_top(istack)->val == '(') {
                char_put('\0');
                return -1;
            }
            char_put(pop(istack)->val);//��ջ��Ԫ�ط������մ�
        }
    }
    char_put('\0');
    return 1;
}
//�·�Ϊ�����׺���ʽ��Ҫ�ĺ���
phead1* initstack1()//����ջ
{
    phead1* istack = (phead1*)malloc(sizeof(phead1));//Ϊͷ�ڵ����ռ�
    if (istack != NULL)//��׳���ж�
    {
        istack->top = NULL;
        istack->size = 0;
    }
    return istack;
}
int isempty1(phead1* istack)//�ж�ջΪ��
{
    if (istack->top == NULL)
    {
        return 1;//ջΪ��
    }
    return 0;//ջ��Ϊ��
}
int seqstack_top1(phead1* istack)//��ȡջ��Ԫ��
{
    if (istack->size != 0)//ջ��Ϊ��
    {
        return istack->top->val;//���ص���ջ��������
    }
    return 99999;
}
int pop1(phead1* istack)//����ջ��Ԫ��
{
    if (isempty1(istack) == 0)//ջ��Ϊ��
    {
        int account = istack->top->val;
        istack->top = istack->top->next;
        istack->size--;//��¼ջ�Ĵ�С
        return account;//���ص��������ݽڵ�
    }
    return 99999;
}
void push1(phead1* istack, int x)//ѹջ(��ջ)
{
    pnode1* temp;//����ѹջ�����ݽڵ�
    temp = (pnode1*)malloc(sizeof(pnode1));
    temp->val = x;
    temp->next = istack->top;
    istack->top = temp;//�䵱ջ��
    istack->size++;//��¼ջ��С�ı仯
    return;
}
int express(int left, int right, char op)//opΪ�����,����������
{
    switch (op)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right == 0)
        {
            return 999;
        }
        return left / right;
    default:
        break;
    }
    return -1;
}
int getsize(phead1* stack) {
    return stack->size;
}
int calculate(char str[])//�����׺���ʽ
{
    phead1* istack2 = initstack1();//����ջ
    int i = 0;
    while (str[i] != '\0')//����������׺���ʽ
    {
        char a[6] = { 0 };
        int index = 0;
        if (is_number(str[i]) == 1)
        {
            while (is_number(str[i]) == 1)
            {
                a[index] = str[i];
                index++;
                i++;
            }
           push1(istack2, atoi(a));//����������ջ
        }
        else if (is_operator(str[i]) == 1)
        {
            int right = pop1(istack2);
            int left = pop1(istack2);
            int ret = express(left, right, str[i]);
            if (ret == 999)//������Ϊ0��
            {
                printf("��������б�����Ϊ0\n");
                return 999;
            }
            push1(istack2, ret);//��������ջ
        }
        else if (str[i] == ' '){}
        else
        {
            printf("error\n");
            break;
        }
        i++;
    }
    if (str[i] == '\0' && getsize(istack2))
        return seqstack_top1(istack2);
    return 0;
}
int main()
{
    char str[1024] = { 0 };//������ÿ��Ԫ�ظ�ֵΪ'\0'
    while (1) {
        printf("����������������ʽ:\n");
        scanf("%s", str);
        int number = transform(str);
        if (number == -1) {
            printf("����ı��ʽ����,����������...\n");
            index = 0;
            continue;
        }
        else if (number == 1) {
            printf("��׺���ʽΪ: %s\n", buffer);
        }
        else {
            index = 0;
            continue;
        }
        //�ɹ����ɺ�׺���ʽ
        //�·������׺���ʽ
        int num = calculate(buffer);
        index = 0;
        if (num == 999)
            continue;
        if (number == 1) {
            printf("������Ϊ:%d\n", num);
            continue;
        }
    }
}


