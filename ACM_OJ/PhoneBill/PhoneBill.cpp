#include <iostream>
using namespace std;

int main()
{
    int fee = 0, threshold = 0;
    while (cin >> fee >> threshold)
    {
        if (fee == 0 && threshold == 0)
            break;
        int total = fee;
        while (fee >= threshold)
        {
            int welfare = fee / threshold, extra = fee % threshold;
            fee = welfare + extra;
            total += welfare;
        }
        cout << total << endl;
    }
    return 0;
}