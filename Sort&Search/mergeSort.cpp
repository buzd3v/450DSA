#include <bits/stdc++.h>
using namespace std;

void merge(int *a, int p, int q, int r)
{
    int *b;
    int i = 0;
    int left = p;
    int mid = q + 1;
    while (left <= q && mid <= r)
    {
        if (a[left] <= a[mid])
        {
            b[i] = a[left];
            i++;
            left++;
        }
        else
        {
            b[i] = a[mid];
            mid++;
            i++;
        }
    }
    while (left <= q)
    {
        b[i] = a[left];
        i++;
        left++;
    }
    while (mid <= r)
    {
        b[i] = a[mid];
        i++;
        mid++;
    }
    for (int j = 0; j <= i; j++)
    {
        a[p] = b[j];
        p++;
    }
}
void mergeSort(int *a, int p, int q)
{
    if (p < q)
    {
        int mid = (p + q) / 2;
        mergeSort(a, p, mid);
        mergeSort(a, mid + 1, q);
        merge(a, p, mid, q);
    }
}
int main()

{
    int a[] = {3, 45, 3, 6, 3, 6, 4, 34, 3214};
    mergeSort(a, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        std::cout << a[i] << " ";
    }
}