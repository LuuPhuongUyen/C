//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <string.h>
#include <conio.h>

void reverse(char s[])
{
    char *t;
    char a[20][40];
    int count = 0;
    t = strtok(s, " ");
    while (t != '\0')
    {
        strcpy(a[count++], t);
        t = strtok('\0', " ");
    }
    strcpy(s, "");
    for (int i = --count; i >= 0; i--)
    {
        strcat(s, a[i]);
        strcat(s, " ");
    }
}
// void reverse(char s[])
// {
//     int i, len;
//     len = strlen(s);
//     printf("\nThe reversed string: ");
//     for (i = len - 1; i >= 0; i--)
//     {
//         if (s[i] == ' ')
//         {
//             s[i] = '\0';
//             //printf("%s ", &s[i] + 1);
//             printf("%s ", s + i + 1);
//         }
//     }
// }
int main()
{
    char s[100];
    printf("Please enter string: ");
    gets(s);
    printf("\nThe reversed string: ");
    reverse(s);
    printf("%s", s);
    getch();
    return 0;
}
