#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100000];
int X[100000];
int t[10000];
int cnt = 0;
int f = 0;

void log(int *x)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << X[i] << " ";
    }
    printf("\n");
}
int Try(int k)
{

    for (int i = 1; i <= (m - f - t[k + 1]) / a[k]; i++)
    {
        X[k] = i;
        f += a[k] * X[k];
        if (k == n - 1)
        {
            if (f == m)
            {
                cnt++;
                // log(X);
            }
        }
        else
        {
            Try(k + 1);
        }
        f -= a[k] * X[k];
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(X, 0, sizeof(int));
    memset(t, 0, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            t[i] += a[j];
        }
    }
    cout << Try(0) << endl;
}