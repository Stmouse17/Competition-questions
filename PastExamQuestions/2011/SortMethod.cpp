#include <iostream>


/*
The definition of median in this question:
1.The middle one of an odd number of integers
2.The nth integer among an even number of integers (2n)

The first method:
Construct an ordered sequence by selecting
smaller numbers from two arrays in ascending order.
The median is obtained by constructing the nth number.
*/

int Median(int A[], int B[], int n)
{
    int i = 0, j = 0, count = 0, current = 0;
    while (count < n)
    {
        if (i >= n)
            current = B[j++];
        else if (j >= n) 
            current = A[i++];
        else if (A[i] < B[j])
            current = A[i++];
        else
            current = B[j++];
        count++;
    }
    return current;
}

int main()
{
    int A[] = { 11, 13, 15, 17, 19 };
    int B[] = { 2, 4, 6, 8, 20 };
    std::cout << Median(A, B, 5);
    return 0;
}

