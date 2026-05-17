#include <iostream>
#include <cstring>
using namespace std;

int parent[35];
int dista[35];

int main()
{
    int N;
    while (cin >> N)
    {
        memset(parent, 0, sizeof(parent));
        memset(dista, -1, sizeof(dista));
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            parent[a] = b;
        }
        int t = 1;
        int d = 0;
        while (parent[t] != 0)
        {
            t = parent[t];
            d++;
            dista[t] = d;
        }
        t = 2;
        d = 0;
        while (parent[t] != 0)
        {
            t = parent[t];
            d++;
            if (dista[t] != -1)
            {
                int d1 = dista[t];
                int d2 = d;
                if (d1 > d2)
                    cout << "You are my elder" << endl;
                else if (d1 < d2)
                    cout << "You are my younger" << endl;
                else
                    cout << "You are my brother" << endl;
                break;
            }
        }
    }
    return 0;
}