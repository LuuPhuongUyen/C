#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
int exist(char *filename)
{
    int existed = FALSE;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        existed = TRUE;
        fclose(f);
    }
    return existed;
}
int writeFile(char *filename)
{
    char c;
    int CTRL_Z = -1;
    if (exist(filename) == 1)
    {
        printf("The file %s existed. Override it Y/N?\n", filename);
        if (toupper(getchar()) == 'N')
            return FALSE;
    }
    FILE *f = fopen(filename, "w");
    fflush(stdin);
    do
    {
        c = getchar();
        if (c != CTRL_Z)
            fputc(c, f);
    } while (c != CTRL_Z);
    fclose(f);
    return TRUE;
}
int printFile(char *filename)
{
    char c;
    if (exist(filename) == 0)
    {
        printf("The file %s does not exist.\n", filename);
        return FALSE;
    }
    FILE *f = fopen(filename, "r");
    while ((c = fgetc(f)) != EOF)
        putchar(c);
    fclose(f);
    return TRUE;
}
int main(int argCount, char *arg[])
{
    if (writeFile("D:\\C\\assem.txt") == 1)
        printf("Writing the file done\n");
    else
        printf("Cannot write this file\n");

    if (printFile("D:\\C\\assem.txt") == 1)
        printf("Reading the file done\n");
    else
        printf("Cannot read this file\n");
    getch();
    return 0;
}
