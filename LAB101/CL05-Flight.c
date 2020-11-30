#include <stdio.h>
#include <stdlib.h>
#define MDAY 10

typedef char string[100];
typedef struct flg
{
    int noSeat;
    string from;
    string to;
} flight;
typedef struct Fli
{

    flight *DB;
    int no;
    int **seatArr;
} Flights;

//=====================LOAD=========================
Flights LoadFlight(string fn)
{
    Flights F;
    FILE *file;
    file = fopen(fn, "r");
    fscanf(file, "%d\n", &F.no);
    if (file == NULL)
    {
        printf("ERROR with opening file");
        getchar();
    }
    F.DB = (flight *)malloc(F.no * sizeof(flight));
    int f;
    for (f = 0; f < F.no - 1; f++)
    {
        flight flg;
        fscanf(file, "%s %s %d\n", flg.from, flg.to, &flg.noSeat);
        F.DB[f] = flg;
    }
    fclose(file);
    return F;
}
/* void InitSeat(Flights *F)
{
    F.seat = (int **)malloc(MDAY * sizeof(int *));
    int d;
    for (d = 0; d < MDAY - 1; d++)
    {
    }
} */
void display(Flights F)
{
    int f;
    for (f = 0; f < F.no - 1; f++)
    {
        flight flg = F.DB[f];
        printf("Flying from %s to %s with %d seats\n", flg.from, flg.to, flg.noSeat);
    }
}
int main()
{
    Flights F = LoadFlight("D:\\C\\LAB\\flight.txt");
    display(F);
    getch();
}
