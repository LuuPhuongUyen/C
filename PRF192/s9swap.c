#include <stdio.h>

int swap(int a, int b)
{
    int t;
    printf("In swap, var. a, add.:%u, value:%d\n", &a, a);
    printf("In swap, var. b, add.:%u, value:%d\n", &b, b);
    printf("In swap, var. t, add.:%u, value:%d\n", &t, t);
    t = a;
    a = b;
    b = t;
}
int main()
{
    int a = 5, b = 7;
    printf("In main, var. a, add.: %u, value: %d\n", &a, a);
    printf("In main, var. b, add.: %u, value: %d\n", &b, b);
    printf("Addr. of main(): %u\n", &main);
    printf("Addr. of swap(...): %u\n", &swap);
    swap(a, b);
    printf("After swapping a and b\n");
    printf("a=%d, b=%d\n", a, b);
    getchar();
    return 0;
}
