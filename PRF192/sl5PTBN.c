#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    float a, b, x;
    printf("Phuong trinh bac nhat mot an:ax+b=0\n", a, b);
    printf("Nhap he so a, b:");
    scanf("%f%f", &a, &b);
    if (a == 0)
    {
        if (b == 0)
            printf("Phuong trinh co vo so nghiem");
        if (b != 0)
            printf("Phuong trinh vo nghiem");
    }
    else
    {
        printf("Phuong trinh co nghiem duy nhat x=%f", -b / a);
    }
    getch();
}
