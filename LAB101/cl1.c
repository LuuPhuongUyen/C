//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>

typedef char string[100];
int main()
{
    int i;
    string w, input;
    int inputlen, wLen;
    //addLength("D:\\C\\LAB\\dictionary.txt", "D:\\C\\LAB\\dictionaryLen.txt");
    for (;;)
    {
        printf("\n\nWelcome to Spell checker");
        printf("\nPlease input: ");
        gets(input);
        inputlen = strlen(input);
        if (input[0] == '\0')
            break;
        FILE *f = fopen("D:\\C\\LAB\\dictionaryLen.txt", "r");
        for (;;)
        {
            fscanf(f, "%d %s\n", &wLen, w);
            if (feof(f))
                break;
            if (inputlen == wLen)
            {
                if (strcmp(input, w) == 0)
                    printf("\n%s is in the dictionary", w);
                if (isPermutation(w, input) == 1)
                    printf("\n%s permutation", w);
                if (matchScore(input, w) < 3)
                    printf("\n%s match", w);
            }
            else
            {
                int diffLen = wLen - inputlen;
                if (abs(diffLen) <= 2)
                {
                    if (diffLen <= 0 && strstr(input, w) != NULL)
                        printf("\n%s sub", w);
                    else if (diffLen > 0 && strstr(w, input) != NULL)
                        printf("\n%s super", w);
                    else if (diffLen <= 0 && isSubsequence(input, w) == 1)
                        printf("\n%s sub", w);
                    else if (diffLen > 0 && isSubsequence(input, w) == 1)
                        printf("\n%s super", w);
                }
            }
        }
        fclose(f);
    }
    getch();
    return 0;
}
void addLength(string fn, string fn2)
{
    FILE *f, *f2;
    f = fopen(fn, "r");
    f2 = fopen(fn2, "w");
    string w;
    if (f == NULL || f2 == NULL)
    {
        printf("\nError when opening the file!");
        getch();
        return;
    }
    fprintf(f2, "%d\n", 349900);
    for (;;)
    {
        fscanf(f, "%s\n", w);
        if (feof(f))
            break;
        fprintf(f2, "%d %s\n", strlen(w), w);
    }
    fclose(f);
    fclose(f2);
}
int isPermutation(string w, string input)
{
    int len1 = strlen(w), len2 = strlen(input), i;
    int count[26] = {0};
    if (len1 != len2)
        return 0;
    for (i = 0; w[i] && input[i]; i++)
    {
        count[w[i] - 'a']++;
        count[input[i] - 'a']--;
    }
    for (i = 0; i < 26; i++)
        if (count[i])
            return 0;

    return 1;
}
int isSubsequence(string input, string w)
{
    char *p = (char *)w;
    for (int i = 0; input[i] != '\0'; i++)
    {
        p = strchr(p, input[i]);
        if (p == NULL)
            return 0;
        p++;
    }
    return 1;
}
int matchScore(string input, string w)
{
    int len1 = strlen(input), len2 = strlen(w), count = 0;
    if (len1 != len2)
        return -1;
    for (int i = 0; i < len1; i++)
    {
        if (input[i] != w[i])
            count++;
    }
    return count;
}