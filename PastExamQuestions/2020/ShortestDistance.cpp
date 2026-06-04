#include <iostream>

/*
Analyzing a problem requires grasping the decisive factors
1.D=∣a−b∣+∣b−c∣+∣c−a∣= 2(max(a,b,c)−min(a,b,c))
  the middle element has no effect on D
2.Using Greedy algorithm, Find the two numbers with
  the smallest difference from three arrays 
  (the two numbers come from different arrays).
*/

int min_3(int a, int b, int c)
{
    int t = a < b ? a : b;
    return t < c ? t : c;
}

int max_3(int a, int b,int c)
{
    int t = a > b ? a : b;
    return t > c ? t : c; 
}

int MinDistance(int S1[], int S2[], int S3[], int n, int m, int p)
{
    int i, j, k;
    i = j = k = 0;
    int minDis = 0x7fffffff;
    while (i < n && j < m && k < p)
    {
        int a = S1[i], b = S2[j], c = S3[k];
        int min3 = min_3(a, b, c);
        int max3 = max_3(a, b, c);
        int D = 2 * (max3 - min3);
        if (D < minDis)
            minDis = D;
        if (minDis == 0)
            return 0;
        if (min3 == a)
            i++;
        else if (min3 == b)
            j++;
        else
            k++;
    }
    return minDis;
}

int main()
{
    int S1[] = { -1,0,9 };
    int S2[] = { -25,-10,10,11 };
    int S3[] = { 2,9,17,30,41 };
    int ans = MinDistance(S1, S2, S3, 3, 4, 5);
    std::cout << ans << std::endl;
    return 0;
}

//tip:reviewing the old helps us learn the new