#include "../headerFiles/log.h"

/*
Generate the below pattern

1
2  3
4  5  6
7  8  9  10
11 12 13 14 15

*/

int main()
{
    int k = 1;
    for(int i=1; i<6; i++)
    {
        for(int j=0; j<i; j++)
        {
            Log(k);
            Log("\t");
            k++;
        }
        Lognd("");
    }
}
