#include <iostream>
#include <cstring>

int FindMinMissingPosition(int A[], int n)
{
    int miss = 0;
    int* B = (int*)malloc(sizeof(int) * n);
    int i, j;
    memset(B, sizeof(int) * n, 0);
    for (i = 0; i < n; i++)
    {
        if (A[i] > 0 && A[i] <= n)
            B[A[i] - 1] = 1;
    }
    for (j = 0; j < n; j++)
    {
        if (B[j] == 0)
        {
            miss = j + 1;
            break;
        }
    }
    if (j == n)
        miss = n + 1;
    return miss;
}

int main()
{
    int A[] = { 3, 4, -1, 1 };
    int n = sizeof(A) / sizeof(A[0]);
    int missingPosition = FindMinMissingPosition(A, n); 
    std::cout << missingPosition << std::endl;
    return 0;
}