#include <stdio.h>
#include <string.h>

void unlock(char lock[], char key[])
{
    int lock_len = strlen(lock);
    int key_len = strlen(key);
    for (int i = lock_len; i >= lock_len / 2; i--)
        lock[i + key_len] = lock[i];
    for (int j = 0; j < key_len; j++)
        lock[j + lock_len / 2] = key[j];
    printf("%s\n", lock);
}

int main()
{
    int n;
    char lock[100];
    char key[100];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        fgets(lock, 100, stdin);
        fgets(key, 100, stdin);
        lock[strcspn(lock, "\n")] = '\0';
        key[strcspn(key, "\n")] = '\0';
        unlock(lock, key);
    }
    return 0;
}