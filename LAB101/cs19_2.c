//Luu Phuong Uyen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char string[100];
typedef struct room
{
    string name;
    int no;
} Room;
int main()
{
    int n, ncommand;
    printf("Enter number of rooms: ");
    scanf("%d", &n);
    Room *R = (Room *)malloc(n * sizeof(Room));
    for (int i = 0; i < n; i++)
        strcpy(R[i].name, "");
    string fn = "D:\\C\\LAB\\hotellog.txt";
    FILE *f = fopen(fn, "r");
    string fn2 = "D:\\C\\LAB\\summary.txt";
    FILE *f2 = fopen(fn, "w");
    fscanf(f, "%d\n", &ncommand);
    for (int i = 1; i <= ncommand; i++)
    {
        string com;
        fscanf(f, "%[^ ]", com);
        printf("%20s", com);
        if (!strcmp(com, "OCCUPANCY"))
        {
        }
        else
        {
            string name;
            // //Bo qua space, doc ten
            fscanf(f, " ");
            if (!strcmp(com, "CHECKIN"))
            {
                int no;
                fscanf(f, "%[^ ] %d", name, &no);
                printf("%10s", name);
                printf("%4d", no);
                //CheckIn(R, n, name, no);
            }
            else
            {
                fscanf(f, "%[^\n]", name);
                printf("%10s", name);
            }
        }
        fscanf(f, "\n");
        printf("\n");
    }
    getch();
    return 0;
}
int Search(Room *R, int n, string name)
{
    for (int i = 0; i < n; i++)
        if (!strcmp(R[i].name, name))
            return i;
    return -1;
}
void CheckIn(Room *R, int n, string name, int no, FILE *f2)
{
    int ind = Search(R, n, "");
    if (ind == -1)
    {
        printf("The hotel is full");
        fprintf(f2, "The hotel is full");
    }
    else
    {
        printf("%s was checked into room %d", name, ind);
        fprintf(f2, "%s was checked into room %d", name, ind);
        strcpy(R[ind].name, name);
        R[ind].no = no;
    }
}
void CheckOut(Room *R, int n, string name, int no)
{
    int ind = Search(R, n, name);
    if (ind == -1)
        printf("Sorry there is no occupant named %s", name);
    else
    {
        printf("%s was checked out of room %d", name, ind);
        strcpy(R[ind].name, "");
        R[ind].no = 0;
    }
}