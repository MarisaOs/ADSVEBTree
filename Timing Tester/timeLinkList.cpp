#include <stdio.h>
#include <fstream>
#include <iostream> 
#include <list>

using namespace std;
int main()
{
    //Read in from file
    FILE *ArrayValueFile;
    ArrayValueFile = fopen("test.txt", "r");
 
    list<int>arr;
    for ( int x = 0 ; x < 250000; x++)
    {
        int num;
        fscanf(ArrayValueFile, "%d", &num);
        arr.push_front(num);
    }

    int dup[10000];
    FILE *DupFile;
    DupFile = fopen("duplicates.txt", "r");
 
    for ( int x = 0 ; x < 10000; x++)
    {
        fscanf(DupFile, "%d", &dup[x]);
    }

    //Search LinkList
    for(auto x = arr.begin(); x != arr.end(); x++)
    {
        for( int y = 0; y < 10000; y++)
        {
            if(*x == dup[y] )
            {
                cout << "Found" << dup[y];
            }
        }
    }

}