#include "../headerFiles/log.h"

/*
Generate the below pattern

* * * * * * * * *
  * * * * * * *
    * * * * *
      * * *
        *

*/

int main()
{
    for(int i=5; i>0; i--)
    {
        // Below loop will pring the spaces to form the pyramid
        for(int k=0; k<(5-i); k++)
            Log("  ");

        for(int j=1; j<=((i*2)-1); j++)
        {
            Log("* ");
        }
        Lognd("");
    }
}
