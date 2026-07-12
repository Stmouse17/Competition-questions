#include <stdio.h>
#include <string.h>

/*
    Three important pieces about recursion
    1.What does this function represent? (Clarify the meaning of a recursive function)
    2.If the scale is even smaller, how do I call myself? (Design recursion relationships)
    3.How small does the scale need to be before it no longer needs to call itself? (Determine the termination condition)

    Determining the recursion termination condition
    ———— Analyze the scenarios represented by the leaf nodes of the recursion tree.
*/

void PostOrder(char pre[], char in[], int preL, int preR, int inL, int inR)
{
    if (preL > preR)
        return;
    char root = pre[preL];
    int k;  //root index in char in[]
    for (k = inL; k <= inR; k++)
    {
        if (in[k] == root)
            break;
    }
    int leftsize = k - inL;
    PostOrder(pre, in, preL + 1, preL + leftsize, inL, k - 1);
    PostOrder(pre, in, preL + leftsize + 1, preR, k + 1, inR);
    printf("%c", root);
}

int main()
{
    char pre[100];
    char in[100];
    while (scanf("%s %s", pre, in) != EOF)
    {
        int n = strlen(pre);
        PostOrder(pre, in, 0, n - 1, 0, n - 1);
        printf("\n");
    }
    return 0;
}