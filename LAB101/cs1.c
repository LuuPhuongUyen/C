//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <string.h>
#include <conio.h>
void reverse(char s[], char *out[])
{
    out[0] = '\0';
    int i, j, n, len;
    len = strlen(s);
    printf("\nThe reversed string: ");
    for (i = len - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            s[i] = '\0';
            //printf("%s ", &s[i] + 1);
            printf("%s ", s + i + 1);
            strcat(out[], s[i]);
            strcat(out[], " ");
            strcat(" ", s[i]);
        }
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
    char st[10][30];
    printf("Please enter string: ");
    gets(s);
    reverse(s, st);
    printf("%s", s);
    getch();
    return 0;
}
