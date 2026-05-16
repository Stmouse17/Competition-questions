#include <stdio.h>

/*
In fact, I think this question
is out of touch with reality
*/

int main()
{
    int fee = 0;
    int threshold = 0;
    while (scanf("%d %d", &fee, &threshold) != EOF)
    {
        if (fee == 0 && threshold == 0)
            break;
        int total = fee;
        while (fee >= threshold)
        {
            int welfare = fee / threshold;
            int extra = fee % threshold;
            fee = extra + welfare;
            total += welfare;
        }
        printf("%d\n", total);
    }
    return 0;
}