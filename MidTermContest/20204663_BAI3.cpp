#include <bits/stdc++.h>

using namespace std;

int sum;
int q = 0;
int Sum(const vector<int> &v)
{
    return std::accumulate(v.begin(), v.end(), 0);
}

void combinationUtil(vector<int> arr, vector<int> &data, int start, int end, int index, int k)
{
    if (index == k)
    {
        if (Sum(data) == sum)
        {
            q++;
            return;
        }
    }

    for (int i = start; i <= end && end - i + 1 >= k - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i + 1, end, index + 1, k);
    }
}

void printCombination(vector<int> &arr, int n, int k)
{
    vector<int> data(k);
    combinationUtil(arr, data, 0, n - 1, 0, k);
}

int main()
{
    int n, k;

    cin >> n >> k >> sum;

    int a[10000];
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> arr(a, a + n);

    printCombination(arr, n, k);
    std::cout << q << std::endl;
    return 0;
}