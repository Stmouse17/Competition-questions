#include <stdio.h>

int main()
{
    int num_heap = 0;
    while (scanf("%d ", &num_heap) != EOF)
    {
        if (num_heap == 0)
            break;
        int num_block = 0;
        int block[50] = { 0 };
        int total = 0;
        for (int i = 0; i < num_heap; i++)
        {
            scanf("%d ", &num_block);
            if (num_block > 100 || num_block < 1)
            printf("Illegal number of building blocks");
            block[i] = num_block;
            total += num_block;
        }
        int average = total / num_heap;
        int num_move = 0;
        for (int j = 0; j < num_heap; j++)
        {
            if (block[j] > average)
                num_move += (block[j] - average);
        }
        printf("%d\n\n", num_move);
    }
    return 0;
}