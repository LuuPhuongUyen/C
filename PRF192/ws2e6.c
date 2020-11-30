//Luu Phuong Uyen SE1401
#include <stdio.h>

int main()
{
    int code;
    char ch;
    for (code = 0; code <= 255; code++)
    {
        printf("%c : %3d    %o: %X\n", code, code, code, code);
        if (code != 0 && code % 20 == 0)
            getchar();
    }
    getch();
}