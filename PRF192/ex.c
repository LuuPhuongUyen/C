// #include<stdio.h>
// int main()
// {
//     char mess[]="more";
//     char *ptr;
//     ptr=mess+strlen(mess);
//     while(ptr>mess) printf("%s",--ptr);
//     getch();
// }

// #include <stdio.h>
// int main()
// {
//     int x = 3, y = 2;
//     int z = x /= y %= 2;
//     printf("%d\n", z);
//     getch();
// }

// #include <stdio.h>
// void main()
// {
//     int b = 6;
//     int c = 7;
//     int a = ++b + c--;
//     printf("%d", a);
//     getch();
// }

//   #include <stdio.h>
//     void main()
//     {
//         double b = 5 % 3 & 4 + 5 * 6;
//         printf("%lf", b);
//         getch();
//     }

//  #include <stdio.h>
//     int main()
//     {
//         int x = 1, y = 2;
//         int z = x & y == 2;
//         printf("%d\n", z);
//         getch();
//     }

// #include <stdio.h>
//     int main()
//     {
//         printf("C programming %s", "Class by\n%s Sanfoundry", "WOW");
//         getch();
//     }

// #include <stdio.h>
// int main()
// {
//     int var = 010;
//     printf("%d", var);
//     getch();
// }
//  #include <stdio.h>
//     int x = 0;
//     int main()
//     {
//         int i = (f() + g()) | g(); //bitwise or
//         int j = g() | (f() + g()); //bitwise or
//         printf("%d",i);
//     getch();
//     }
//     int f()
//     {
//         if (x == 0)
//             return x + 1;
//         else
//             return x - 1;
//     }
//     int g()
//     {
//         return x++;
//     }

// #include <stdio.h>
//     int main()
//     {
//         int i = 0;
//         int j = i++ + i;
//         printf("%d\n", j);
//         getch();
//     }

//    #include <stdio.h>
//     int main()
//     {
//         int a = 1, b = 1, d = 1;
//         printf("%d, %d, %d", ++a + ++a+a++, a++ + ++b, ++d + d++ + a++);
//         getch();
//     }

//   #include <stdio.h>
//     void main()
//     {
//         double b = 5 & 3 && 4 || 5 | 6;
//         printf("%lf", b);
//         getch();
//     }

//  #include <stdio.h>
//     int main()
//     {
//         int a[5] = {1, 2, 3, 4, 5};
//         int i;
//         for (i = 0; i < 5; i++)
//             if ((char)a[i] == '5')
//                 printf("%d\n", a[i]);
//             else
//                 printf("FAIL\n");
//                 getch();
//     }

// #include <stdio.h>
//     void main()
//     {
//         int x = 4, y, z;
//         y = --x;
//         z = x--;
//         printf("%d%d%d", x, y, z);
//         getch();
//     }

// #include <stdio.h>
//     int main()
//     {
//         int x = 1;
//         int y =  x == 1 ? getchar(): 2;
//         printf("%d\n", y);
//         getch();
//     }
//    #include <stdio.h>
//     int main()
//     {
//         int x = 1, y = 2;
//         if (x && y == 1)
//             printf("true\n");
//         else
//             printf("false\n");
//     }
    // #include <stdio.h>
    // int main()
    // {
    //     int a = 2;
    //     int b = 0;
    //     int y = (b == 0) ? a :(a > b) ? (b = 1): a;
    //     printf("%d\n", y);
    // }
    // #include <stdio.h>
    // int main()
    // {
    //     int x = 3, y = 2;
    //     int z = x << 1 > 5;
    //     printf("%d\n", z);
    // }
    //  #include <stdio.h>
    // int main()
    // {
    //     int x = 2, y = 0;
    //     int z;
    //     z = (y++, y);
    //     printf("%d\n", z);
    //     return 0;
    // }

    //  #include <stdio.h>
    // int main()
    // {
    //     int x = 2;int y = 2;
    //     float f = y + x /= x / y;
    //     printf("%d %f\n", x, f);
    //     return 0;
    // }
    //  #include <stdio.h>
    // int main()
    // {
    //     int x = 0, y = 2;
    //     int z = ~x & y;
    //     printf("%d\n", z);
    // }
    //   #include <stdio.h>
    // int main()
    // {
    //     int x = 2, y = 0;
    //     int z = (y++) ? 2 : y == 1 && x;
    //     printf("%d\n", z);
    //     return 0;
    // }
    #include <stdio.h>
      int main()
    {
        int x = 3, i = 0;
        do {
            x = x++;
            i++;
        } while (i != 3);
        printf("%d\n", x);
        getch();
    }
    