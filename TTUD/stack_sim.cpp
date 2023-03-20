#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

void pop()
{
    if (s.size() == 0)
        std::cout << "NULL" << std::endl;
    else
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}
void push(int v)
{
    s.push(v);
}
int main()
{
    std::string query;
    while (std::cin >> query)
    {
        if (query.compare("PUSH") == 0)
        {
            int v;
            std::cin >> v;
            push(v);
        }
        else if (query.compare("POP") == 0)
        {
            pop();
        }
        else
        {
            break;
        }
    }
    return 0;
}