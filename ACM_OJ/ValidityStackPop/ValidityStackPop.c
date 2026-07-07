#include <stdio.h>

//Important Topics！！！

int main()
{
    int n;
    while (scanf("%d", &n) && n != 0)
    {
        int a[150];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int stack[150];
        int top = -1;       //top
        int current = 1;    //1 2 3 4 5 push onto the stack
        int legality = 1;
        for (int i = 0; i < n; i++)
        {
            while ((top == -1 || stack[top] != a[i]) && current <= n)
                stack[++top] = current++;
            if (top != -1 && stack[top] == a[i])
                top--;
            else
            {
                legality = 0;
                break;
            }
        }
        if (legality)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}