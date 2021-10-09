#include <stdio.h>

void printDesc();

void printShiftingMenu();

long long int shifting(long long int iNumber, int inputBits, int direction);

void decToBin(long long iNumber);

int binaryDigits[100];

int main()
{

    long long int inputNumber = 0;

    int inputDirection = 0;

    int inputBits = 0;

    do
    {

        printDesc();

        scanf("%lld", &inputNumber);

        if (inputNumber != 0)
        {

            printf("\n  -- Your number is: %lld ", inputNumber);

            decToBin(inputNumber);

            printShiftingMenu();

            scanf("%d", &inputDirection);
            do
            {

                if (inputDirection == 1)
                {

                    printf("  -- Enter how many bits? ");

                    scanf("%d", &inputBits);

                    if (inputBits == 0)
                    {
                        break;
                    }

                    inputNumber = shifting(inputNumber, inputBits, inputDirection);

                    printf("\n\n -- Your number now is : %lld  ", inputNumber);

                    decToBin(inputNumber);

                }
                else if (inputDirection == 2)
                {
                     printf("  -- Enter how many bits? ");

                    scanf("%d", &inputBits);

                    if (inputBits == 0)
                    {
                        break;
                    }

                    inputNumber = shifting(inputNumber, inputBits, inputDirection);

                    printf("\n\n -- Your number now is : %lld  ", inputNumber);

                    decToBin(inputNumber);
                }
                else if (inputDirection == 0)
                {
                    printf("");
                }
                else
                {
                    printf("\n\n !! Invalid direction !! \n\n");
                }

            } while (inputDirection != 0);
        }
        else
        {
            printf("  -- GoodBye! --  \n");
        }

    } while (inputNumber != 0);

    return 0;
}

void printDesc()
{

    printf("\n\n  -- Bits shifter --  \n\n");

    printf("  -- Enter number 0 for quit. --  \n\n");

    printf("  -- Please enter your number: ");
}

void printShiftingMenu()
{
    printf("\n  -- Shift direction -- \n\n");

    printf("  -- Enter 0 bits for quit -- \n\n");

    printf("  -- Enter 1 for left -- \n\n");

    printf("  -- Enter 2 for right -- \n\n");

    printf("  -- Please enter your direction: ");
}

long long int shifting(long long int iNumber, int inputBits, int direction)
{

    long long int tempNumber = iNumber; // user number but temp

    if (direction == 1)
    { // left direction
        tempNumber = tempNumber << inputBits;
    }
    else
    {
        tempNumber = tempNumber >> inputBits; // right direction
    }

    return tempNumber;
}

void decToBin(long long int iNumber)
{

    long long int tempNumber = iNumber; // user number but temp

    if(tempNumber == 0) {
        for(int i = 0; i < 4; i++) {
            binaryDigits[i] = 0;
        }

         printf("(");

         for (int i = 0; i < 4; i++) {

            printf("%d", binaryDigits[i]);

         }

    printf(")\n");

    } else {

    long long int rem = 0; //we will get reminder from here

    int counter = 0;

    while (tempNumber > 0)
    {

        rem = tempNumber % 2; //we get remainder;

        binaryDigits[counter] = rem;

        tempNumber = tempNumber / 2;

        counter++;
    }


    printf("(");

    for (int i = counter - 1; i >= 0; i--)
    {

        printf("%d", binaryDigits[i]);
    }
    printf(")\n");

    }
    
}
