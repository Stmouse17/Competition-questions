#include <stdio.h>

/*
    In the problem, the latter part (suffix) of i represents
the valid range of values ​​for the second multiplier.
    A left-to-right scanning method results in a single processing size starting from n.
As i progresses, the effective range of values ​​continuously shrinks, rendering the
previous scan ineffective for the next. Adopting a right-to-left 
approach allows for optimization using the idea of ​​state recursion.
*/

void calMuLMax(int A[], int res[], int n)
{
    int max_pos = 0, max_neg = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] > max_pos)
            max_pos = A[i];
        else if (A[i] < max_neg)
            max_neg = A[i];
        if (A[i] > 0)
            res[i] = A[i] * max_pos;
        else
            res[i] = A[i] * max_neg;
    }
}

int main()
{
    int A[] = { 1, 4, -9, 6 };
    int res[4] = { 0 };
    calMuLMax(A, res, 4);
    for (int j = 0; j < 4; j++)
        printf("%d ", res[j]);
    return 0;
}