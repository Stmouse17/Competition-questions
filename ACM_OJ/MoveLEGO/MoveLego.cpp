#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        int heights[50];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
            sum += heights[i];
        }
        int avg = sum / n;
        int moves = 0;
        for (int j = 0; j < n; j++) 
        {
            if (heights[j] > avg)
                moves += (heights[j] - avg);
        }
        cout << moves << endl;
        cout << endl;
    }
    return 0;
}