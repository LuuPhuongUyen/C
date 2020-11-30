#include <stdio.h>
#include <string.h>
#include <conio.h>
char *Ltrim(char s[])
{
    int i = 0;
    while (s[i] == ' ')
        i++;
    if (i > 0)
        strcpy(&s[0], &s[i]);
    return s;
}
char *Rtrim(char s[])
{
    int i = strlen(s) - 1;
    while (s[i] == ' ')
        i--;
    s[i + 1] = '\0';
    return s;
}
char *trim(char s[])
{
    Rtrim(Ltrim(s));
    char *ptr = strstr(s, "  ");
    while (ptr != NULL)
    {
        strcpy(ptr, ptr + 1);
        ptr = strstr(s, "  ");
    }
    return s;
}
void nhap(char names[][31], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Nhap ten thu %d/%d:", i + 1, n);
        fflush(stdin);
        scanf("%30s[^\n]", names[i]);
        trim(names[i]);
    }
}
void xuat(char names[][31], int n)
{
    int i;
    for (i = 0; i <= n; i++)
        puts(names[i]);
}
void swap(char *names[][31], int n)
{
    int i, j;
    char t[30];
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if ((names[i] < names[j]))
            {
                char t = *names[i];
                *names[i] = *names[j];
                *names[j] = t;
            }
}
void sapxep(char names[][31], int n)
{
    int i, j;
    char t[31];
    swap(*names[], n);
}
int main()
{
    char names[10][30];
    int n = 5;
    nhap(names, n);
    xuat(names, n);
    sapxep(names, n);
    printf("Sau khi sap xep:\n");
    xuat(names, n);
    getch();
    return 0;
}