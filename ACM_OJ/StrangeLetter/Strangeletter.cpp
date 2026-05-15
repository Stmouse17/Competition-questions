#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    while (cin >> n)
    {
        int sum = 0;
        while (n > 0)
        {
            int dight = n % 10;
            if (dight % 2 == 0)
                sum += dight;
            n /= 10;
        }
        cout << sum << endl << endl;
    }
    return 0;
}