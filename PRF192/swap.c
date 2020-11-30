#include <stdio.h>
//swap 2 intergers
void swap  (int *px, int *py)
{
    int t;
    t = *px;
    *px = *py;
    *py = t;
}
int main()
{
    int a = 5;
    int b = 7;
    printf("a = %d, b = %d\n", a, b);
    swap ( &a, &b);
    printf("a = %d, b = %d\n", a, b);
    getch();
    return 0;
}
// #include <stdio.h>
// //swap 2 intergers
// void swap  (int px, int py)
// {
//     int t;
//     t = px;
//     px = py;
//     py = t;
// }
// int main()
// {
//     int a = 5;
//     int b = 7;
//     printf("a = %d, b = %d\n", a, b);
//     swap ( &a, &b);
//     printf("a = %d, b = %d\n", a, b);
//     getch();
//     return 0;
// }