#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int convertBinaryToDecimal() {
    int binaryNumber;
    int decimalNumber = 0, power = 0, remainder, check;

    char bDigits[2] = {'0', '1'};
    char b[30];
    int i, j, digit = 0;
    long long decimal = 0, e = 0;
    do {
        check = 1;
        printf("Enter Binary number: ");
        fflush(stdin);
        gets(b);
        for (int i = 0; i < strlen(b); i++)
            if (b[i] != 48 && b[i] != 49) {
                check = 0;
                printf("Invalid\n");
                break;
            }
    } while (binaryNumber != 0);
    for (int i = 0; i < strlen(b); i++) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, power);
        ++power;
    }
    printf("Decimal num %d", decimalNumber);

    return decimalNumber;
}

int convertOctalToDecimal(int octalNumber) {
    int decimalNumber = 0, i = 0;
    long long octal, tempOctal, decimal;
    int rem, place;
    tempOctal = octal;

    decimal = 0;
    place = 0;
    while (tempOctal != 0) {
        rem = tempOctal % 10;
        decimal += pow(8, place) * rem;
        tempOctal /= 10;

        place++;
    }
    i = 1;

    return decimalNumber;
}

void convertHexaToDecimal() {
    int decimalNumber = 0;
    char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
        '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char hexadecimal[30];
    int i, j, power = 0;
    printf("Enter a Hexadecimal Number\n");
    scanf("%s", hexadecimal);
    // Converting hexadecimal number to decimal number //
    for (i = strlen(hexadecimal) - 1; i >= 0; i--) {
        // search currect character in hexDigits array //
        for (j = 0; j < 16; j++) {
            if (hexadecimal[i] == hexDigits[j]) {
                decimalNumber += j * pow(16, power);
            }
        }
        power++;
    }

    printf("Decimal Number : %d\n ", decimalNumber);
}

int menu() {
    int choice;
    char c;
    printf("\n");
    printf("1. Binary to Decimal\n");
    printf("2. Octal to Decimal\n");
    printf("3. Hexa to Decimal\n");
    printf("Input your choice: ");
    while (scanf("%d%c", &choice, &c) != 2 || c != 10 || choice < 0 || choice > 4) {
        fflush(stdin);
        printf("Input again: ");
    }
    return choice;

}

int main() {
    int choice;
    int binaryNumber;
    int octalNumber;
    char c;
    do {
        choice = menu();
        switch (choice) {

            case 1:

                //                printf("Enter a Binary Number\n");
                //                while (scanf("%d%c", &binaryNumber, &c) != 2 || c != 10) {
                //                    printf("input again: ");
                //                }

                printf("Decimal number: %d", convertBinaryToDecimal(binaryNumber));
                break;
            case 2:
                printf("Enter an octal number: ");
                while (scanf("%d%c", &octalNumber) != 2 || c != 10) {
                    printf("input again: ");
                }

                printf("%d in octal = %d in decimal", octalNumber, convertOctalToDecimal(octalNumber));


                //              printf("%d in octal = %d in decimal", octalNumber, convertOctalToDecimal(octalNumber));

                break;
            case 3:
                convertHexaToDecimal();
                break;

        }
    } while (choice < 1 && choice > 3);
    getchar();
    main();
    return (EXIT_SUCCESS);
}