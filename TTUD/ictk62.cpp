// Write C program that reads an integer value N from stdin, prints to stdout the number Q
// ways to assign values 1, 2, …, 9 to characters I, C, T, H, U, S, K
// (characters are assigned with different values) such that:

// ICT - K62 + HUST = N

// Input

// Unique line contains an integer N (1 <= N <= 105)

// Output

// Write the value Q

// Example

// Input
// 2000
// Output
// 28

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

string a = "CHIKSTU";
set<char> s_set = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int N;
map<char, char> nmap;
int c_count = 0;
void s_insert(map<char, char> t, const char &key, const char &value)
{
    if (t.find(key) != t.end())
    {
        t.erase(key);
        t.insert({key, value});
    }
    else
        t.insert({key, value});
}
int convert(string S)
{
    string k = "";
    for (auto i : S)
    {
        if ('A' <= i && i <= 'Z')
        {
            k += nmap[i];
        }
        else
            k += i;
    }
    return atoi(k.c_str());
}
bool check()
{
    int t = convert("ICT") - convert("K62") + convert("HUST");
    if (t == N)
        return true;
    return false;
}

ostream &operator<<(ostream &output, map<char, char> const &m)
{
    for (auto idx : m)
    {
        output << idx.first << ": " << idx.second << ", ";
    }
    output << endl;
    return output;
};
ostream &operator<<(ostream &output, set<char> const &s)
{
    for (auto idx : s)
    {
        output << idx << " ";
    }
    // output << endl;
    return output;
}
ostream &operator<<(ostream &output, vector<char> s)
{
    for (auto idx : s)
    {
        output << idx << " ";
    }
    output << endl;
    return output;
}
void count_t(int k)
{

    for (auto i : s_set)
    {
        nmap.insert({a[k], i});
        s_set.erase(i);
        std::cout << "_____________________________ " << endl;
        std::cout << s_set << ": i = " << i << " k = " << k << endl;
        std::cout << nmap;
        if (k == 6)
        {
            if (check())
            {
                c_count++;
                std::cout << nmap;
            }
        }
        else
        {
            count_t(k + 1);
        }
        s_set.insert(i);
        std::cout << "set inserted: " << i << endl;
        nmap.erase(a[k]);
        std::cout << "nmap erases: " << a[k] << endl;
        std::cout << "set now: " << s_set << endl;
        std::cout << "nmap now: " << nmap;
        std::cout << "_____________________________ " << endl;
    }
}
int main()
{
    std::cin >> N;
    count_t(0);
    std::cout << c_count << std::endl;
}
