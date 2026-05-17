#include <stdio.h>
#include <string.h>

int main()
{
    int parent[35];
    int dist[35];
    int N;
    while (scanf("%d", &N) != EOF)
    {
        memset(parent, 0, sizeof(parent));
        memset(dist, -1, sizeof(dist));
        for (int i = 0; i < N; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            parent[a] = b;
        }
        int t = 1;
        int d = 0;
        while (parent[t] != 0)
        {
            t = parent[t];
            d++;
            dist[t] = d;
        }
        t = 2;
        d = 0;
        while (parent[t] != 0)
        {
            t = parent[t];
            d++;
            if (dist[t] != -1)
            {
                int d1 = dist[t];
                int d2 = d;
                if (d1 > d2)
                    printf("You are my elder\n");
                else if (d1 < d2)
                    printf("You are my younger\n");
                else
                    printf("You are my brother\n");
                break;
            } 
        }
    }
    return 0;
}