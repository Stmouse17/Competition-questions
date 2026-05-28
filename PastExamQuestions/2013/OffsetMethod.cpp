#include <iostream>

/*
Properties of the main element:
1.Count of occurrences > n/2;
2.Therefore, after removing each pair of distinct elements,
  the final remaining element will always be x.
OffsetMethod(Boyer-Moore Majority Vote Algorithm):
1.First pass: Find "candidate main elements";
2.Second pass: Verify if it really exceeds n/2.
*/

int MajorityElement(int a[], int n)
{
    int candidate = a[0];
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            candidate = a[i];
        }
        else if (a[i] == candidate)
            count++;
        else if (a[i] != candidate)
            count--;
    }
    count = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == candidate)
            count++;
    }
    if (count > n / 2)
        return candidate;
    else 
        return -1;
}

int main()
{
    int a[] = { 0,5,5,3,5,7,5,5 };
    int n = 8;
    int majority = MajorityElement(a, n);
    std::cout << majority << std::endl;
    return 0;
}