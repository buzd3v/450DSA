#include <bits/stdc++.h>
using namespace std;

void insert(int x, priority_queue<int> &v)
{
    v.push(x);
}
void deleteMax(priority_queue<int> &v)
{
    std::cout << v.top() << std::endl;
    v.pop();
}
int main()
{
    int n;
    cin >> n;
    int a[100000];
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    std::priority_queue<int> v(a, a + n);

    string query;
    while (cin >> query)
    {
        if (query.compare("insert") == 0)
        {
            int value;
            cin >> value;
            insert(value, v);
        }
        else if (query.compare("delete-max") == 0)
        {
            deleteMax(v);
        }
        else
        {
            break;
        }
    }
    return 0;
}