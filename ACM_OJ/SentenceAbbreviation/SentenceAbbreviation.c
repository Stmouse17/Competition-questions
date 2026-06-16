#include <stdio.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char s[200];
    while (n--)
    {
        fgets(s,sizeof(s),stdin);
        if (s[0] != ' ' && s[0] != '\n')
            putchar(toupper(s[0]));
        for (int i = 1; s[i]; i++)
        {
            if (s[i] != ' ' && s[i-1] == ' ')
                putchar(toupper(s[i]));
        }
        printf("\n");
    }
    return 0;
}