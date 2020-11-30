//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void add(char name[][21], char make[][21], int volume[], int price[], int duration[], int *n)
{
	int ok;
	do
	{
		printf("Name: ");
		fflush(stdin);
		scanf("%21[^\n]", name[*n]);
		ok = (name[*n][0] != 32);

		if (ok)
		{
			printf("Make: ");
			fflush(stdin);
			scanf("%s", make[*n]);

			printf("Volume: ");
			fflush(stdin);
			scanf("%d", &volume[*n]);

			printf("Price: ");
			fflush(stdin);
			scanf("%d", &price[*n]);

			printf("Duration: ");
			fflush(stdin);
			scanf("%d", &duration[*n]);
			printf("\n");
			(*n)++;
		}
	} while (ok);
	printf("List: \n");
	sort(name, make, volume, price, duration, *n);
}
void printmake(char name[][21], char make[][21], int volume[], int price[], int duration[], int n)
{
	int i, count = 0;
	char maker[21];
	printf("Enter make to find: ");
	scanf("%s", maker);
	for (i = 0; i <= n; i++)
	{
		if (strcmp(make[i], maker) == 0)
		{
			printf("Name: %s\nMake:%s\nVolume:%d\nPrice: %d\nDuration:%d\n\n", name[i], make[i], volume[i], price[i], duration[i]);
			count++;
		}
	}
	if (count <= 0)
		printf("Maker does not found!");
}
void printvol(char name[][21], char make[][21], int volume[], int price[], int duration[], int n)
{
	int i, num1, num2, count = 0;
	printf("Enter v1: ");
	scanf("%d", &num1);

	printf("Enter v2: ");
	scanf("%d", &num2);

	for (i = 0; i <= n; i++)
	{
		if (volume[i] > num1 && volume[i] < num2)
		{
			printf("Name: %s\nMake:%s\nVolume:%d\nPrice: %d\nDuration:%d\n\n", name[i], make[i], volume[i], price[i], duration[i]);
			count++;
		}
	}
	if (count <= 0)
	{
		printf("Volume not found!");
	}
}
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void swapString(char a[], char b[])
{
	char t[31];
	strcpy(t, a);
	strcpy(a, b);
	strcpy(b, t);
}
void sort(char name[][21], char make[][21], int volume[], int price[], int duration[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
		{
			if (volume[j] > volume[j + 1] || volume[j] == volume[j + 1] && price[j] > price[j + 1])
				swap(&volume[j], &volume[j + 1]);
			swapString(name[j], name[j + 1]);
			swapString(make[j], make[j + 1]);
			swap(&price[j], &price[j + 1]);
			swap(&duration[j], &duration[j + 1]);
		}
	for (i = 0; i < n; i++)
	{
		printf("Name: %s\nMake:%s\nVolume:%d\nPrice: %d\nDuration:%d\n\n", name[i], make[i], volume[i], price[i], duration[i]);
	}
}
int main()
{
	char name[50][21], make[50][21];
	int volume[50], price[50], duration[50];
	int n = 0, option;
	printf("1. Adding some new soft drink \n");
	printf("2. Print out items which belong to a known make \n");
	printf("3. Printing out items whose volumes are between v1 and v2 ( integers)  \n");
	printf("4. Printing the list in ascending order based on volumes then prices \n");
	printf("5. Exit\n");
	do
	{
		printf("Enter option: ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("---------------------------------- \n");
			add(name, make, volume, price, duration, &n);
			break;
		case 2:
			printf("---------------------------------- \n");
			printmake(name, make, volume, price, duration, n);
			break;
		case 3:
			printf("---------------------------------- \n");
			printvol(name, make, volume, price, duration, n);
			break;
		case 4:
			printf("---------------------------------- \n");
			sort(name, make, volume, price, duration, n);
			break;
		case 5:
			exit(0);
			break;
		}
	} while (option >= 1 && option <= 5);
}
