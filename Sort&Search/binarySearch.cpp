#include <bits/stdc++.h>

bool binary_search(int *a, int left, int right, int x)
{
    int mid = (left + right) / 2;
    if (left >= right)
        return false;
    if (a[mid] == x)
        return true;
    else
    {
        if (a[mid] > x)
            binary_search(a, left, mid, x);
        else
            binary_search(a, mid + 1, right, x);
    }
}
int main()
{

    int a[] = {1, 2, 3, 4, 6, 7, 8, 9, 33};
    std::cout << &a;
}