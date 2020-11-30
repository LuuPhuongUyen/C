//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 50
char name[100][50];
void corectName(char *s)
{
    char *name = (char *)calloc(50, sizeof(char));

    int i, j = -1;
    for (i = 0; i < strlen(s); i++)
        //Nhieu dau cach
        if ((s[i] == ' ') && (s[i + 1] == ' '))
            continue;
        //Dau cach o dau ten
        else if ((j == -1) && (s[i] == ' '))
            continue;
        //Dau cach o cuoi ten
        else if ((i == strlen(s) - 1) && (s[i] == ' '))
            continue;
        else
        {
            j++;
            name[j] = s[i];
            name[j] = toupper(name[j]);
        }
    s[i] = strupr(s[i]);
    strcpy(s, name);
    free(name);
}
void output(char s[][31], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d.%s \n", i, s[i]);
}
void input(char s[][31], int *n)
{
    int ok;
    char name[31];
    do
    {
        printf("input a name:");
        fflush(stdin);
        scanf("%30[^\n]", name);

        ok = (name[0] != 32);
        corectName(name); //ok=(name[0]!=' '); // *Note: press keySPACE for codes[i] to exit
        if (ok)
        {
            strcpy(s[*n], name);
            (*n)++;
        }
    } while (ok);
    // if (checkName(name) == 0)
    //     printf("WRONG NAME FORMAT!\n");
    printf("After adding: \n");
    output(s, *n);
}
int findPos(char name[], char s[][31], int n)
{
    for (int i = 0; i < n; i++)
        if (strcmp(s[i], name) == 0)
            return i;
    return -1;
}
void find(char name[], char s[][31], int n)
{
    int pos = findPos(name, s, n);
    if (pos >= 0)
        printf("Name '%s' found at position %d\n", s[pos], pos);
    else
        printf("Name not found! \n");
}
void rm(char name[], char s[][31], int *n)
{
    int pos = findPos(name, s, *n);
    if (pos >= 0)
    {
        printf("Name '%s' found at position %d\n", s[pos], pos);
        for (int i = pos; i < (*n - 1); i++)
            strcpy(s[i], s[i + 1]);
        (*n)--;
        printf("After deleting: \n");
        output(s, *n);
    }
    else
        printf("Name not found! \n");
}
void swap(char a[], char b[])
{
    char t[31];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}
void sort(char s[][31], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(s[i], s[j]) > 0)
                swap(s[i], s[j]);
    printf("After sorting in ascending order: \n");
    output(s, n);
}
int getchoice()
{
    int choice;
    printf("Enter your option: ");
    scanf("%d", &choice);
    return choice;
}
int main()
{
    int option, n = 0;
    char s[MAXN][31], name[31];
    printf("1- Add a student\n");
    printf("2- Remove a student\n");
    printf("3- Search a student\n");
    printf("4- Print the list in ascending order\n");
    printf("5- Quit \n");
    do
    {
        option = getchoice();
        switch (option)
        {
        case 1:
            input(s, &n);
            break;
        case 2:
            printf("Who do you want to remove? ");
            fflush(stdin);
            scanf("%30[^\n]", name);
            rm(name, s, &n);
            break;
        case 3:
            printf("Enter name to search: ");
            fflush(stdin);
            scanf("%30[^\n]", name);
            find(name, s, n);
            break;
        case 4:
            fflush(stdin);
            scanf("%30[^\n]", name);
            sort(s, n);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Choice again\n");
            break;
        }
    } while ((option >= 1) && (option <= 5));
    getch();
    return 0;
}