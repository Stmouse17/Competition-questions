#include <stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int sum = 0;
        while (n > 0)
        {
            int dight = n % 10;
            if (dight % 2 == 0)
                sum += dight;
            n /= 10;
        }
        printf("%d\n\n", sum);
    }
    return 0;
}