//Luu Phuong Uyen SE1401
#include <stdio.h>

int main()
{
    int opt;
    printf("1 - Calculating Fuel Economy\n");
    printf("2 - Calculating Distance Traveled\n");
    printf("3 - Revised Fuel Economy Calculation\n");
    do
    {
        printf("\n\nChoice feature:  ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            funtion1();
            break;
        case 2:
            funtion2();
            break;
        case 3:
            funtion3();
            break;
        }
    } while (opt > 0 && opt <= 3);
    getch();
    return 0;
}

void funtion1()
{
    int time;
    float speed, gallons;
    printf("How many minutes did you drive?\n");
    scanf("%d", &time);
    printf("What was the average speed of the car during that time?\n");
    scanf("%f", &speed);
    printf("How many gallons of gas did your car use?\n");
    scanf("%f", &gallons);
    printf("Your car averaged %.2f miles per gallon.\n", speed / 60 * time / gallons);
}

void funtion2()
{
    float radius;
    int revolutions;
    printf("What is the radius of your tires, in inches?\n");
    scanf("%f", &radius);
    printf("How many revolutions did your car's tires make?\n");
    scanf("%d", &revolutions);
    printf("Your car traveled %.2f miles.\n", 3.14 * 2 * radius * 0.000015783 * revolutions);
}

void funtion3()
{
    float radius, gallons;
    int revolutions;
    printf("What is the radius of your tires, in inches?\n");
    scanf("%f", &radius);
    printf("How many revolutions did your car's tires make?\n");
    scanf("%d", &revolutions);
    printf("How many gallons of gas did your car use?\n");
    scanf("%f", &gallons);
    printf("Your car averaged %.2f miles per gallon.\n", 3.141592654 * 2 * radius * revolutions * 0.000015783 / gallons);
}
