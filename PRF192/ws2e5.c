//Luu Phuong Uyen SE1401
#include <stdio.h>

int main()
{
    int vowels = 0, consonants = 0, others = 0;
    char ch;
    printf("Enter a string of characters: ");
    do
    {
        ch = getchar();
        ch = toupper(ch);
        printf("%c", ch);
        if (ch >= 'A' && ch <= 'Z')
        {
            switch (ch)
            {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowels++;
                break;
            default:
                consonants++;
            }
        }
        else if (ch != '\n' && ch != ' ')
            ++others;
    } while (ch != '\n');
    printf("The number of vowels: %d\n", vowels);
    printf("The number of consonants: %d\n", consonants);
    printf("The number of others: %d", others);
    getch();
    return 0;
}