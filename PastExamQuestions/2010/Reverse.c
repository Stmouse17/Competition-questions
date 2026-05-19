#include <stdio.h>

void Reverse(int R[], int left, int right)
{
    int temp;
    while (left < right)
    {
        temp = R[left];
        R[left++] = R[right];
        R[right--] = temp;
    }
}

void LeftShift(int R[], int n, int p)
{
    Reverse(R, 0, p - 1);
    Reverse(R, p, n - 1);
    Reverse(R, 0, n - 1);
}

int main()
{
    int R[] = { 1,2,3,4,5,6,7 };
    LeftShift(R, 7, 3);
    for (int i = 0; i < 7; i++)
        printf("%d ", R[i]);
    return 0;
}