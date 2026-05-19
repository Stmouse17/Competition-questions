#include <stdio.h>

void Swap(int R[], int start1, int start2, int length)
{
    for(int i = 0; i <length; i++)
    {
        int temp = R[start1 + i];
        R[start1 + i] = R[start2 + i];
        R[start2 + i] = temp;
    }
}

void LeftShift(int R[], int n, int p)
{
    int i = p;      //A = the first p items
    int j = n - p;  //B = the last n-p items
    while(i != j)
    {
        if(i < j)   //A is shorter than B
        {
            Swap(R, p - i, p + j - i, i);
            j -= i;
        }
        else
        {
            Swap(R, p - i, p, j);
            i -= j;
        }
    }
    Swap(R, p - i, p, i);
}

int main()
{
    int R[] = {1,2,3,4,5,6,7};
    int n = 7;
    int p = 3;
    LeftShift(R, n, p);
    for(int i = 0; i < n; i++)
        printf("%d ", R[i]);
    return 0;
}