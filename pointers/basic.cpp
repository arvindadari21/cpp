#include "../headerFiles/log.h"


void increment(int* value)
{
    (*value)++;
}

int main()
{
    int a = 10;

    Log("Before incrementing the value: ");
    Log(a);
    Lognd("");

    increment(&a);

    Log("After incrementing the value: ");
    Log(a);
    Lognd("");
}