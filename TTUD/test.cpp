#include <bits/stdc++.h>
using namespace std;
// ostream &operator<<(ostream &out, vector<any> s)
// {
//     for (auto i : s)
//     {
//         out << i << " ";
//     }
//     out << std::endl;
//     return out;
// }
int main()
{
    vector<any> s;
    string k = "kien";
    int z = 5;
    s.push_back(k);
    s.push_back(z);
    int t = any_cast<int>(s[1]);
    std::cout << t << " " << endl;
}