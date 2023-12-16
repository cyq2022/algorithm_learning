#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define N 100010

int head, e[N], ne[N], idx;

void init()
{
    head = -1;
    idx = 0;
}

// 插到头节点
void add_to_head(int x)
{
    e[idx] = x;      // 储存idx指针指向的值
    ne[idx] = head;  // idx指针指向head指针指向的节点
    head = idx;     // 头节点的指针指向 当前节点
    idx++;
}

// 一般插入  插入到下标为k的点的后面
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

// 将下标为k 的点后面的点删除
void removes(int k)
{
    ne[k] = ne[ne[k]];   // 万一删除的节点后是空节点?
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
        scanf("\n%c", &c);    // 跳过空格字符 ‘\n’

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
                head = ne[head];  // 删除头节点
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