//Luu Phuong Uyen SE1401
#include <stdio.h>
#include <conio.h>
int n = 7;
double x = 20.4;
char c1 = 'u';

int main()
{
    int m = 1;
    short s = 3;
    long l = 1000;
    float y = 1.75;
    printf("Code of main : %u\n", &main);
    printf("Variable n : at addr : %u, value : %d, size : %d\n", &n, n, sizeof(n));
    printf("Variable x : at addr : %u, value : %lf, size : %d\n", &x, x, sizeof(x));
    printf("Variable c1: at addr : %u, value : %c, size : %d\n", &c1, c1, sizeof(c1));
    printf("Variable m : at addr : %u, value : %d, size : %d\n", &m, m, sizeof(m));
    printf("Variable s : at addr : %u, value : %hi, size : %d\n", &s, s, sizeof(s));
    printf("Variable l : at addr : %u, value : %ld, size : %d\n", &l, l, sizeof(l));
    printf("Variable y : at addr : %u, value : %f, size : %d\n", &y, y, sizeof(y));
    getchar();
    return 0;
}