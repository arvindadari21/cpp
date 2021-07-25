#include "../headerFiles/log.h"

/*
Generate the below pattern

           1
         1   1
       1   2   1
     1   3   3   1
   1   4   6   4   1
 1   5   10  10  5   1

*/

int factorial(int number)
{
    if (number == 0)
        return 1;

    return number * factorial(number - 1);
}

int binomial(int numerator, int denominator)
{
    return (factorial(numerator)/(factorial(numerator-denominator) * factorial(denominator)));
}

int main()
{
    for(int i=0; i<6; i++)
    {
        // Below loop will pring the spaces to form the pyramid
        for(int k=7; k>i; k--)
            Log("  ");

        for(int j=0; j<=i; j++)
        {
            Log(binomial(i, j));
            Log("\t");
        }
        Lognd("");
    }
}
