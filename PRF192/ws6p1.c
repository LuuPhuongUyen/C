//Luu Phuong Uyen - SE1401
#include <stdio.h>
#include <string.h>

int checkISBN(char n[])
{// length must be 10 
  int length = strlen(n);
  if (length != 10)
    return -1;
  int i, s = 0;
   // Computing weighted sum  
  for (i = 0; i <= 9; i++)
  {
    int digit = n[i] - '0';
    if (digit < 0 || digit > 9)
      return -1;
    else
      s += (digit * (10 - i));
  }
  if (s % 11 == 0)
    return 0;
}
int main()
{
  char n[20];
  printf("Enter n = ");
  scanf(" %s", &n);
  if (checkISBN(n) == 0)
    puts("Valid");
  else
    puts("Invalid");
  getch();
  return 0;
}