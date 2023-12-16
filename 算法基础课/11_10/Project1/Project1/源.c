//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
////#include <stdio.h>
////#define N 100010
////int n, m;
////int a[3 * N], s[3 * N];
////
////typedef struct {
////    int first;
////    int second;
////}PII;
////
////int alls[3 * N];
////PII add[N], query[2 * N];
////
////int main()
////{
////    scanf("%d %d", &n, &m);
////    for (int i = 1; i <= n; i++)
////    {
////        int a = scanf("%d", &add[i].first);
////        int b = scanf("%d", &add[i].second);
////        add[i].first = a; add[i].second = b;
////        alls[i] = a;
////    }
////
////    return 0;
////}
//
////int unique(int alls[])
////{
////    int j = 1; ///  1 2 2 3 4
////    for (int i = 2; i <= sizeof(alls) / sizeof(alls[0]); i++)            //双指针原地去重
////    {
////        if (alls[i] == alls[j]) {}
////        else
////            alls[++j] = alls[i];
////    }
////    return j;
////}
////
////int main()
////{
////
////    int a[5] = { 1, 2, 2, 3, 4 };
////    printf("%d", unique(a));
////
////    return 0;
////}
//
//#define N 300010
//int n, m;
//int a[N], s[N];
//
//typedef struct {
//    int first;
//    int second;
//}PII;
//
//int alls[N];// 离散化数组0 1 3 4 6 7 8
//PII add[N], query[N];
//
//void quick_sort(int l, int r)
//{
//    if (l >= r)return;
//
//    int i = l - 1, j = r + 1;
//    int x = alls[l + r >> 1];
//
//    while (i < j)
//    {
//        do i++; while (alls[i] < x);
//        do j--; while (alls[j] > x);
//        if (i < j) {
//            int k = alls[j];
//            alls[j] = alls[i];
//            alls[i] = k;
//        }
//    }
//    quick_sort(l, j);
//    quick_sort(j + 1, r);
//}
//
//int unique(int length)
//{
//    // 0 1 2 2 3 3 4 0 0
////       1 2 3 4 0
//    int j = 1;
//    for (int i = 2; i <= length; i++)            //双指针原地去重
//    {
//        if (alls[i] != alls[j])alls[++j] = alls[i];
//    }
//
//    return j - 1;
//}
//
//int find(int x, int length)
//{
//    int l = 1, r = length;
//    while (l < r)
//    {
//        int mid = l + r + 1 >> 1;
//        if (alls[mid] <= x)l = mid;
//        else r = mid - 1;
//        printf(" l=%d ", l);
//    }
//    return l;
//}
//
//int main()
//{
//    scanf("%d %d", &n, &m);
//    int i = 0;
//    for (i = 1; i <= n; i++)
//    {
//        scanf("%d %d", &add[i].first, &add[i].second);
//        alls[i] = add[i].first;
//    }
//    for (int j = 1; j <= m; j++)
//    {
//        scanf("%d %d", &query[j].first, &query[j].second);
//        alls[i++] = query[j].first;
//        alls[i++] = query[j].second;
//    }
//    int length = i - 1;
//    quick_sort(1, length);//排序
//    length = unique(length);//去重 从0开始 0位是0
//    printf("alls length = %d\n", length);
//    for (int i = 1; i <= n; i++)
//    {
//        printf("%d ", add[i].first);
//        int x = find(add[i].first, length);
//        printf("%d\n", x);
//        a[x] += add[i].second;
//    }
//
//    // for(int i = 1;i <= 10;i++)printf("%d ",alls[i]);
//
//    return 0;
//}