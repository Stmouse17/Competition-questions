#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char word[60];
    while (n--)
    {
        scanf("%s", &word);
        for (int i = 0; i < strlen(word); i += 2)
        {
            char temp = word[i];
            word[i] = word[i + 1];
            word[i + 1] = temp;
        }
        printf("%s\n", word);
    }
    return 0;
}