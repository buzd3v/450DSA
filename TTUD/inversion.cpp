#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &output, vector<int> t)
{
    for (int i = 0; i < t.size(); i++)
    {
        output << t[i] << " ";
    }
    output << endl;
    return output;
}
int find(vector<int> &a)
{
    int inv_count = 0;
    int size = a.size();
    vector<int> temp;
    temp.push_back(a[0]);
    std::cout << temp;
    for (int i = 1; i < size; i++)
    {
        auto itr = lower_bound(temp.begin(), temp.end(), a[i]);
        if (binary_search(temp.begin(), temp.end(), a[i]))
            itr++;
        inv_count += temp.end() - itr;
        temp.insert(itr, a[i]);
        std::cout << temp;
    }
    return inv_count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (size_t i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }
        cout << find(a) << endl;
    }
}