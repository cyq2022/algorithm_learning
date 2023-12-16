#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 1010

int n, m, q;
int b[N][N];
int x1, x2, y1, y2, c;

insert(int x1, int y1, int x2, int y2, int c)
{
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            scanf("%d", &x);
            insert(i, j, i, j, x);
        }
    }

    while (q--)
    {
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i <= m; j++)
        {
            b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//#include <stdio.h> 
//#define N 100010
//
//int n;
//int q[N], t[N];
//void marge_sort(int l, int r)
//{
//    if (l >= r)return;
//    int mid = l + r >> 1;
//    marge_sort(l, mid);
//    marge_sort(mid + 1, r);
//    int i = l, j = mid + 1, k = 0;
//    while (i <= mid && j <= r)
//    {
//        // while(q[i] <= q[j])t[k++] = q[i++];
//        // while(q[i] > q[j]) t[k++] = q[j++];
//        // 4 2 2 4 4 
//        /*
//        3 1 2 4 5
//        312    45
//    31   2    4   5
// 3    1
//        */
//        if (q[i] <= q[j])t[k++] = q[i++];
//        else t[k++] = q[j++];
//    }
//    while (i <= mid)t[k++] = q[i++];
//    while (j <= r)t[k++] = q[j++];
//
//    for (int i = l, k = 0; i <= r; i++, k++)q[i] = t[k];
//}
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &q[i]);
//    }
//    marge_sort(0, n - 1);
//    for (int i = 0; i < n; i++) {
//        printf("%d ", q[i]);
//    }
//    return 0;
//}
//
//
















////#include <stdio.h>
//// #include <string.h >
////#include<stdbool.h>
////#define N 100010
//
//// //暴力
//// int n, q[N], t;
//// int res;
//// int m[N];
//// int main()
//// {
//
////     scanf("%d", &n);
////     for (int i = 0; i < n; i++)
////     scanf("%d", &q[i]);
//
////     for (int i = 0; i < n;i++)
////     {
////         t = 0;
////         memset(m, 0, sizeof(m));
////         for (int j = i; j < n; j++)
////         {
////             if (m[q[j]] != 1)
////             {
////                 m[q[j]]++;
////                 t++;
////             }
////             else 
////             {   i = j - 1;
////                 break;
////             }
////         }
//
////         res = res > t ? res : t;
////     }
////     printf("%d", res);
////     return 0;
//// }
//
////int n, q[N], res, s[N];
////
////int max(int a, int b) { return a > b ? a : b; }
////
////bool check(int i, int j)
////{
////    return  q[i] == q[j];
////}
////
////int mian()
////{
////    scanf("%d", &n);
////    for (int i = 0; i < n; i++)scanf("%d", &q[i]);
////
////    for (int i = 0, j = 0; i < n; i++)
////    {
////        s[q[j]]++;
////        while (j <= i && check(i, j))
////        {
////            s[q[j]]--;
////            j++;
////        }
////        res = max(res, i - j + 1);
////    }
////    printf("%d", res);
////    return 0;
////}
//
////9 1 2 2 3 5 6 7 8 9 
////20 7 10 10 4 3 9 7 2 5 5 0 6 6 8 5 2 10 6 5 8
////10 9 3 6 9 5 10 1 2 3 9
//
//
//#include <stdio.h>
//#define N 100010
//int n, m, x, c, l, r, a[N];
//
//typedef struct
//{
//    int key;
//    int value;
//}PII;
//
//PII t[N];
//
//int findl(int l, int r, int x) // 7 8.5 9
//{
//    int mid = t[l + r >> 1].value;
//    while (l >= r)
//    {
//        if (mid >= x)r = mid;
//        else l = mid + 1;
//    }
//    return l;
//}
//int findr(int l, int r, int x)
//{
//    int mid = t[l + r + 1 >> 1].value;
//    while (l >= r)
//    {
//        if (mid <= x)l = mid;
//        else r = mid - 1;
//    }
//}
//
//quick_sort(int l, int r)
//{
//    if (l >= r)return;
//
//    int x = t[l + r >> 1].key;
//    int i = l - 1, j = r + 1;
//
//        while (i < j)
//        {
//            do i++; while (t[i].key < x);
//            do j--; while (t[j].key > x);
//            if (i < j) {
//                PII k = t[j];
//                t[j] = t[i];
//                t[i] = k;
//            }
//        }
//    quick_sort(l, j);
//    quick_sort(j + 1, r);
//}
//
//int main()
//{
//    scanf("%d %d", &n, &m);
//    while (n--)// 从1开始待离散化的值存储
//    {
//        scanf("%d %d", &t[n].key, &t[n].value); //n次操作 往x位置插入c
//
//    }
//    //  do scanf("%d %d",&t[n].key,&t[n].value);  while(--n);  从0开始存
//    //排序去重
//    quick_sort(1, n);
//    for (int i = 2, j = 1; i <= n; i++)
//    {
//        if (t[i].key == t[j].key)t[j].value += t[i].value;
//        else t[++j] = t[i];
//    }
//    n = j;
//    // 1 2 3 3 4 5 6 6 6
//    // 
//    for (int i = 1; i <= n; i++)  b[i] = b[i - 1] + a[i].value;
//
//    //插入
//    while (m--)// 询问l,r
//    {
//        scanf("%d %d", &l, &r);
//        int l = findl(1, n, l);
//        int r = findr(1, n, r);
//        printf("%d", b[r] - b[l - 1]);
//    }
//    return 0;
//}
