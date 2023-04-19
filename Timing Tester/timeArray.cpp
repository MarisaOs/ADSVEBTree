#include <stdio.h>
#include <fstream>
#include <iostream> 

using namespace std;
int main()
{
    //Read in from file
    int arr[250000];
    FILE *ArrayValueFile;
    ArrayValueFile = fopen("test.txt", "r");
 
    for ( int x = 0 ; x < 250000; x++)
    {
        fscanf(ArrayValueFile, "%d", &arr[x]);
    }

    int dup[10000];
    FILE *DupFile;
    DupFile = fopen("duplicates.txt", "r");
 
    for ( int x = 0 ; x < 10000; x++)
    {
        fscanf(DupFile, "%d", &dup[x]);
    }

    //Search for values
    for ( int x = 0; x < 10000; x++)
    {
        for ( int y = 0; y < 250000; y++)
        {
            if ( dup[x] == arr[y])
            {
                cout << "Found " << dup[y] << endl;
            }
        }
    }
}