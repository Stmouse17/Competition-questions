#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n - i; j++)
                printf(" ");
            for (int j = 1; j <= i; j++)
                printf("%d", j);
            for (int j = i - 1; j >= 1; j--)
                 printf("%d", j);
            printf("\n");
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= i; j++)
                printf(" ");
            for (int j = 1; j <= n - i; j++)
                printf("%d", j);
            for (int j = n - 1 - i; j >= 1; j--)
                printf("%d", j);
            printf("\n");
        }
    }
    return 0;
}