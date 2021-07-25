#ifndef _IO_STREAM  // Check if the iostream header file is already defined
#define _IO_STREAM

#include<iostream>

#endif

using namespace std;

void Log(int data)
{
    cout << data;
}

void Log(const char* message)
{
    cout << message;
}

void Lognd(const char* message)
{
    Log(message);
    cout << endl;
}