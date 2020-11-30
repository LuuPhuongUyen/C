//Luu Phuong Uyen SE1401
#include <stdio.h>
typedef char string[100];
typedef int arr[200];

int main()
{
    char s[50];
    printf("Enter string: ");
    fflush(stdin);
    gets(s);
    arr Fre;
    TanSuat(s, Fre);
    printf("\nNhieu nhat\n");
    InCs4(Fre);
    printf("\n\nMot lan\n");
    InCs8(Fre);
    printf("\n\nTan suat\n");
    InCs36(Fre);
    getch();
    return 0;
}
void TanSuat(char s[], arr F)
{
    int i, j;
    for (i = 0; i < 26; i++)
        F[i] = 0;
    for (j = 0; s[j] != '\0'; j++)
        if (isalpha(s[j]))
        {
            char c;
            if (isupper(s[j]))
                c = tolower(s[j]);
            else
                c = s[j];
            F[c - 'a']++; //c is lower
        }
}

int FindMax(arr F)
{
    int i, m = 0;
    for (i = 0; i < 26; i++)
        if (F[i] > m)
            m = F[i];
    return m;
}

void InCs4(arr F)
{
    int i, m = FindMax(F);
    for (i = 0; i < 26; i++)
        if (F[i] == m)
           printf("%c-%d\t", (char)(i + 'a'), F[i]);
}
void InCs8(arr F)
{
    int i, m = FindMax(F);
    for (i = 0; i < 26; i++)
        if (F[i]==1)
            printf("%c-%d\t", (char)(i + 'a'), F[i]);
}
void InCs36(arr F)
{
    int i;
    for (i = 0; i < 26; i++)
        if (F[i] > 0)
            printf("%c-%d\t", (char)(i + 'a'), F[i]);
}