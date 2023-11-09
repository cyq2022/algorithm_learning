#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//int n;
//int q[100010];
//
//void swap(int q[], int i, int  j)
//{
//    int temp = q[j];
//    q[j] = q[i];
//    q[i] = temp;
//}
//
//void quick_soft(int q[], int l, int r)
//{
//    if (l >= r)return;
//    int x = (l + r) >> 1, i = l - 1, j = r + 1;
//
//    while (i < j)
//    {
//        do i++; while (q[i] < q[x]);
//        do j--; while (q[j] > q[x]);
//        if (i < j) swap(q, i, j);
//    }
//    quick_soft(q, l, j);
//    quick_soft(q, j + 1, r);
//}
//
//
//
//int main()
//{
//    //scanf("%d", &n);
//    //for (int i = 0; i < n; i++)
//    //{
//    //    scanf("%d ", &q[i]);
//    //}
//
//    //quick_soft(q, 0, n - 1);
//
//    //for (int i = 0; i < n; i++)
//    //{
//    //    printf("%d ", q[i]);
//    //}
//
//
//    return 0;
//}


//#include <stdio.h>
//
//
//
//const int N = 1e5 + 10;
//
//int n;
//int q[N], tmp[N];
//
//
//void marge_sort(int q[], int l, int r)
//{
//    if (l >= r)return;
//    int mid = l + r >> 1;
//    marge_sort(q, l, mid);
//    marge_sort(q, mid + 1, r);
//
//    int k = 0, i = l, j = mid + 1;
//    while (i <= mid && j <= r)
//    {
//        if (q[i] <= q[j]) tmp[k++] = q[i++];
//        else tmp[k++] = q[j++];
//    }
//
//    while (i <= mid) tmp[k++] = q[i++];
//    while (j <= r) tmp[k++] = q[j++];
//
//    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
//
//}
//
//int main()
//{
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &n);
//    }
//
//    marge_sort(q, 0, n - 1);
//
//    for (int i = 0; i < n; i++)
//    {
//        printf("%d ", q[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//
//#define N 100010
//int n, m, k;
//int q[N];
//
//int main()
//{
//    scanf("%d %d",&n ,&m);
//    
//    for (int i = 0; i < n; i++)scanf("%d", q[i]);
//
//    while (m--)
//    {
//        scanf("%d", &k);
//        // >= x
//        int mid, l = 0, r = n - 1;
//        while (l < r)
//        {
//            mid = l + r >> 1;
//            if (q[mid] >= x) r = mid;
//            else l = mid + 1;
//        }
//
//        if (q[mid] != x) printf("-1 -1");
//        else
//        {
//            printf("%d ", l);
//            l = 0; r = n - 1;
//            while (l < r)
//            {
//                mid = l + r + 1 >> 1;
//                if (q[mid] <= x)l = mid;
//                else r = mid - 1;
//            }
//        }
//        printf("%d", l);
//    }
//
//    return 0;
//}

#include <stdio.h>

#define N 100010
int n, k;
int q[N];

int quick_slect(int l, int r, int k)
{
    while (l >= r)return q[l]; // 若只有一个元素 返回

    int x = q[l + r >> 1]; // 数组随机值
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j)
        {
            int t = q[j];
            q[j] = q[i];
            q[i] = t;
        }
    }
    int sl = j - l + 1;  //一次递归后左边的数多少
    if (sl < k)return quick_slect(j + 1, r, k - sl);   // 易错
    if (sl >= k)return quick_slect(l, j, k);  // 只递归左边

}

int main()
{
    //快速选择算法求出数列从小到大排序后的第 k个数。
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)scanf("%d", &q[i]);

    int res = quick_slect(0, n - 1, k);

    printf("%d", res);
    return 0;
}