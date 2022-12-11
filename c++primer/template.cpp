#include <iostream>
#include <ostream>
template <typename T>
T isBigger(T x, T y)
{
    return x > y ? x : y;
}

class templates
{
public:
    int k;

    bool operator>(const templates &other)
    {
        return this->k > other.k;
    }
    friend std::ostream &operator<<(std::ostream &output, const templates &T)
    {
        output << T.k;
        return output;
    }
};
int main()
{
    templates k1({3});
    templates k2({5});
    std::cout << isBigger(k1, k2) << std::endl;
}
