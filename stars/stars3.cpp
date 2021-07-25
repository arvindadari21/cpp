#include "../headerFiles/log.h"

/*
Generate the below pattern

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

        1
      2 1 2
    3 2 1 2 3
  4 3 2 1 2 3 4
5 4 3 2 1 2 3 4 5

        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5

*/

int main()
{
    //         *
    //       * * *
    //     * * * * *
    //   * * * * * * *
    // * * * * * * * * *

    for(int i=1; i<6; i++)
    {
        // Below loop will pring the spaces to form the pyramid
        for(int k=5; k>i; k--)
            Log("  ");

        for(int j=1; j<=((i*2)-1); j++)
        {
            Log("* ");
        }
        Lognd("");
    }

    Lognd("");
    Lognd("===============================");
    Lognd("");

    //         1
    //       2 1 2
    //     3 2 1 2 3
    //   4 3 2 1 2 3 4
    // 5 4 3 2 1 2 3 4 5

    for(int i=1; i<6; i++)
    {
        // Below loop will pring the spaces to form the pyramid
        for(int k=5; k>i; k--)
            Log("  ");

        int l = i;
        bool increament = false;
        for(int j=1; j<=((i*2)-1); j++)
        {
            if (l==1)
                increament = true;

            Log(l);
            Log(" ");
            if (increament)
                l++;
            else
                l--;
        }
        Lognd("");
    }

    Lognd("");
    Lognd("===============================");
    Lognd("");

    //         1
    //       2 3 2
    //     3 4 5 4 3
    //   4 5 6 7 6 5 4
    // 5 6 7 8 9 8 7 6 5

    for(int i=1; i<6; i++)
    {
        // Below loop will pring the spaces to form the pyramid
        for(int k=5; k>i; k--)
            Log("  ");

        int l = i;
        bool increament = true;
        for(int j=1; j<=((i*2)-1); j++)
        {
            if (l == ((i*2)-1) )
                increament = false;

            Log(l);
            Log(" ");
            if (increament)
                l++;
            else
                l--;
        }
        Lognd("");
    }

}
