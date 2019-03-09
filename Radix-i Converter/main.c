//********************************************************************
//*                    EEE2046F/EEE2050F C template                  *
//*==================================================================*
//* WRITTEN BY: Muzikayise Khuzwayo   	                 		             *
//* DATE CREATED:  6 March                                                  *
//* MODIFIED:                                                        *
//*==================================================================*
//* PROGRAMMED IN: Codeblocks           *
//* TARGET:    PC                                     *
//*==================================================================*
//* DESCRIPTION:  Program which asks user decimal and radix and outputs the                                                    *
//*                                                                  *
//********************************************************************
// INCLUDE FILES
//====================================================================
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//====================================================================
// GLOBAL CONSTANTS
//====================================================================
#define AUTHOR "Muzikayise Khuzwayo"
#define TITLE "DECIMAL TO RADIX-i converter"
#define YEAR "2019"
//====================================================================
// GLOBAL VARIABLES
//====================================================================
int decValue;
int radValue;
//====================================================================
// FUNCTION DECLARATIONS
//====================================================================
char * Dec2RadixI(int decValue, int radValue)
{
    int n=0;
    char c;
    long num=0;
    double logNum=(log(decValue)/log(radValue));
    int arrSize=(int)logNum + 1;
    char radix_i[arrSize];

	while (decValue!=0)
	{
		long b=decValue%radValue;
		decValue=(decValue/radValue);

        if (b<10)
        {
            c=(char)(b+48);
        }
        else
        {
            c=(char)(b+55);
        }

        n+=1;
        radix_i[arrSize-n]=c;
    }
    printf("The radix-%d value of the number is %s\n", radValue, radix_i);

	return &radix_i;
}
//====================================================================
// MAIN FUNCTION
//====================================================================

int main (void)
{
	int number;
	int radix;


	printf("******************************\n");
	printf("%s\n", TITLE);
	printf("Written by: %s\n", AUTHOR);
	printf("Date: %s\n", YEAR);
	printf("******************************\n");
	number=0;

	while(number>=0)
	{
		printf("Enter a decimal number: ");
		scanf("%d", &number);
		if(number<0)
		{
			printf("EXIT");
			break;
		}
		printf("The number you have entered is %d\n", number);
		printf("Enter a radix for the converter between 2 and 16: ");
		scanf("%d", &radix);
		if ((radix>=2 & radix<17))
        {
           printf("The radix you have entered is %d\n", radix);
        }
        else
        {
            if (radix<2)
                printf("The radix you have entered is too small\n");
            if(radix>16)
                printf("The radix you have entered is too large\n");
            continue;
        }

        double logNum=(log(number)/log(radix));
        printf("The log%d of the number is %.2f\n", radix, logNum);

        int div=number/radix;
        printf("The integer result of the number divided by %d is %d\n", radix, div);

        int rem=number%radix;
        printf("The remainder is %d\n", rem);

        char radix_i;

        radix_i=Dec2RadixI(number, radix);
        printf("%s\n", radix_i);//something wrong happening here...


	}

	return 0;
}							// End of main

//********************************************************************
// END OF PROGRAM
//********************************************************************
