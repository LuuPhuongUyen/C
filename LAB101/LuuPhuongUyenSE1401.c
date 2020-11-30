#include <stdio.h>
typedef char string[100];
int main()
{
    int opt;
    string filename;
    printf("1. Enter file name to save content.\n");
    printf("2. Enter content:\n");
    printf("3. Print content.\n");
    do
    {
        printf("\n\nEnter option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            fileName(filename);
            break;
        case 2:
            EnterContent(filename);
            break;
        case 3:
            PrintContent(filename);
            break;
        }
    }

    while (opt >= 1 && opt <= 3);
    getch();
    return 0;
}
void fileName(string filename)
{
    printf("Enter file name: ");
    fflush(stdin);
    gets(filename);
}
void EnterContent(string filename)
{
    FILE *f = fopen(filename, "a+");
    if (!f)
    {
        printf("The file with name %s does not exist !", filename);
        return;
    }
    string input;
    printf("Enter content: ");
    fflush(stdin);
    gets(input);
    fputs(input, f);
    fclose(f);
}
void PrintContent(string filename)
{
    char s;
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("The file with name %s does not exist !", filename);
        return;
    }
    printf("Print content: ");
    while ((s = fgetc(f)) != EOF)
    {
        printf("%c", s);
    }
    fclose(f);
}
