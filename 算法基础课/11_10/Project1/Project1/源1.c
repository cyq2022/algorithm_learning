#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h> 
#define N 100010

int n;
int q[N], t[N];
void marge_sort(int l, int r)
{
    if (l >= r)return;
    int mid = l + r >> 1;
    marge_sort(l, mid);
    marge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        // while(q[i] <= q[j])t[k++] = q[i++];
        // while(q[i] > q[j]) t[k++] = q[j++];
        // 4 2 2 4 4 
        /*
        3 1 2 4 5
        312    45
    31   2    4   5
 3    1
        */
        if (q[i] <= q[j])t[k++] = q[i++];
        else t[k++] = q[j++];
    }
    while (i <= mid)t[k++] = q[i++];
    while (j <= r)t[k++] = q[j++];

    for (int i = l, k = 0; i <= r; i++, k++)q[i] = t[k];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    marge_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }
    return 0;
}
