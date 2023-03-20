#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int A, B;
void findSubSequences(int *a, int n, int k)
{
    int begin = 0;
    int end = k - 1;
    int sum = 0;
    for (int i = begin; i <= end; i++)
    {
        sum += a[i];
    }
    if (sum <= B && A <= sum)
    {
        cnt++;
        // std::cout << a[begin] << a[end] << endl;
    }
    while (end < n - 1)
    {
        ++end;
        sum = sum + a[end] - a[begin];
        begin++;
        if (sum <= B && A <= sum)
        {
            cnt++;
            // std::cout << a[begin] << a[end] << endl;
        }
    }
}
int main()
{
    int n, k;
    std::cin >> n >> k >> A >> B;
    int a[100000];

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    findSubSequences(a, n, k);
    std::cout << cnt << std::endl;
    return 0;
}