#include <stdio.h>
int main()
{
    int n = 260, *p = &n;
    printf("n=%d\n", n);
    char *pp = (char *)p;
    *pp = 0;
    printf("n=%d\n", n);
    getch();
}

// #include <stdio.h>
// int t(int x, int y, int z)
// {
//     int k = 2 * x + 3 * y + 5 * z;
//     return k % 13;
// }
// int main()
// {
//     int a = 7, b = 6, c = 5;
//     int L = t(a, b, c);
//     printf("L=%d", L);
//     getch();
// }

// #include <stdio.h>
// void T(int *p, int *q)
// {
//     int t = *p;
//     *p = *q;
//     *q = t;
// }
// int main()
// {
//     int a = 7, b = 6;
//     T(&a, &b);
//     printf("a=%d, b=%d", a, b);
//     getch();
// }

// #include <stdio.h>
// int T(int *p, int *q)
// {
//     int t = (*p) + (*q) > 12 ? 5 : 6;
//     return 2 * t % 5;
// }
// int main()
// {
//     int a = 3, b = 4, c;
//     c = T(&a, &b);
//     printf("c=%d", c);
//     getch();
// }