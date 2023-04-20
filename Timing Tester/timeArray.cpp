#include <stdio.h>
#include <iostream> 

using namespace std;
int main()
{
    //Read in from file
    int arr[500000];

    for ( int x = 0; x < 500000; x++)
    {
        arr[x] = x;
    }

    for ( int x = 0; x < 500000; x++)
    {
        if ( arr[x] == 250001)
        {
            cout << "Found" << endl;
        }
    }
}