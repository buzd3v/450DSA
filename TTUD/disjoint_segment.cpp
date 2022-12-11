#include <bits/stdc++.h>
using namespace std;
bool check(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
    {
        if (b.first < a.second)
            return false;
    }
    if (b.first < a.first)
    {
        if (a.first < b.second)
            return false;
    }
    return true;
}
int findMaxCadinality(const vector<pair<int, int>> &k)
{
    for (int i = 0; i < k.size(); i++)
    {
    }
}
ostream &operator<<(std::ostream &output, std::pair<int, int> k)
{
    output << k.first << " " << k.second << endl;
    return output;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> k(n);

    for (int i = 0; i < n; i++)
    {
        cin >> k[i].first >> k[i].second;
    }
    sort(k.begin(), k.end(), [](pair<int, int> x, pair<int, int> y)
         { return x.second < y.second; });
    for (int i = 0; i < n; i++)
    {
        std::cout << k[i];
    }
}