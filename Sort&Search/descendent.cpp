#include <bits/stdc++.h>
using namespace std;
class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window)
    {
        int count = 0;
        double asbounce = h * bounce;
        if (0 >= bounce || 1 <= bounce)
            return -1;
        if (h <= 0)
            return -1;
        if (window >= h)
            return -1;
        while (asbounce >= window)
        {
            count++;
            asbounce = bounce * asbounce;
        }
        return count;
    }
};
int main()
{
    Bouncingball b;
    std::cout << Bouncingball::bouncingBall(3, 0.66, 1.5) << std::endl;
}
