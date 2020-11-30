//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void blank(char s[])
{
    int i, first = 0, last;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == ' ')
        {
            last = i - 1;
            //printf("[%d, %d]", first, last);
            Nan(s, first, last);
            int j, k;
            for (j = i + 1; s[j] == ' '; j++)
                ;
            int d = (j - (i + 1));
            for (k = j; s[k] != '\0'; k++)
                s[k - d] = s[k];
            s[k - d] = '\0';
            first = i + 1;
        }
    last = i - 1;
    //printf("[%d, %d]\n", first, last);
    Nan(s, first, last);
}
void Nan(char s[], int first, int last)
{
    //Nắn kí tự đầu từ
    if (isalpha(s[first]) && islower(s[first]))
        s[first] = toupper(s[first]);
    //Nắn kí tự ở giữa
    for (int k = first + 1; k <= last; k++)
    {
        if (isalpha(s[k]) && isupper(s[k]))
            s[k] = tolower(s[k]);
    }
}
int main()
{
    char s[30];
    printf("Enter string: ");
    gets(s);
    blank(s);
    puts(s);
    getch();
    return 0;
}