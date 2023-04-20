#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, bool>arr;

    for ( int x = 0 ; x < 500000; x++)
    {
        arr.insert({x, true});
    }

    //Search
    std:: unordered_map<int, bool>::const_iterator got= arr.find(250001);
    if( got == arr.end())
    {
       cout<< "Not Found" << endl;
    }
    else
    {
       cout <<  "Found" << endl;
    }
}