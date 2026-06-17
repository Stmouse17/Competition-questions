#include <stdio.h>
#include <ctype.h>
 
//Simulating the scanning process and determining
//the sequence of steps is crucial.
 
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char s[200];
    for (int i = 0; i < n; i++)
    {
        fgets(s, sizeof(s), stdin);
        int j = 0;
        while (s[j] != '\0' && s[j] != '\n')
        {
            while (s[j] == ' ')
                j++;
            if (s[j] != '\0' && s[j] != '\n')
                putchar(toupper(s[j]));
            while (s[j] != ' ' && s[j] != '\0' && s[j] != '\n')
                j++;
        }
        printf("\n");
    }
    return 0;
}