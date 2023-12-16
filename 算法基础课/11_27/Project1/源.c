#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define N 100010

int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

// �嵽ͷ�ڵ�
void add_to_head(int x)
{
    e[idx] = x;      // ����idxָ��ָ���ֵ
    ne[idx] = head;  // idxָ��ָ��headָ��ָ��Ľڵ�
    head = idx;     // ͷ�ڵ��ָ��ָ�� ��ǰ�ڵ�
    idx++;
}

// һ�����  ���뵽�±�Ϊk�ĵ�ĺ���
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// ���±�Ϊk �ĵ����ĵ�ɾ��
void removes(int k)
{
    ne[k] = ne[ne[k]];   // ��һɾ���Ľڵ���ǿսڵ�?
}

int main()
{
    int m;
    scanf("%d", &m);
    init();
    while (m--)
    {
        char c;
        int k, x;
        scanf("\n%c", &c);    // �����ո��ַ� ��\n��

        if (c == 'H')
        {
            scanf("%d", &x);
            add_to_head(x);

        }

        if (c == 'D')
        {
            scanf("%d", &k);
            if (k)
                removes(k - 1);   // k != 0 
            else
                head = ne[head];  // ɾ��ͷ�ڵ�
        }

        if (c == 'I')
        {
            scanf("%d %d", &k, &x);
            add(k - 1, x);
        }

    }

    for (int i = head; i != -1; i = ne[i])printf("%d ", e[i]);

    return 0;
}