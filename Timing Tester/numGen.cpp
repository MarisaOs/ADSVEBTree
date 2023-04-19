#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
//Little Array
    int num;
    int counter;
    int arr[10000];

    srand((unsigned)time(NULL));

    while( counter != 10000)
    {
        num = rand();
        for ( int x = 0; x < counter; x++)
        {
            if ( num == arr[x])
            {
                num = rand();
                x = 0;
            }
        }
        arr[counter] = num;
        counter++;
    }

    ofstream MyFile("duplicates.txt");

    for ( int y = 0; y < counter; y++)
    {
        MyFile << arr[y] << endl;
    }

    MyFile.close();

cout << "Little Array done" << endl;
//Big Array

    int bigArray[250000];
    counter = 0;
    while( counter != 250000)
    {
        num = rand();
        for ( int x = 0; x < counter; x++)
        {
            if ( num == bigArray[x])
            {
                num = rand();
                x = 0;
            }
        }
        bigArray[counter] = num;
        counter++;
    }

    ofstream MyFile2("test.txt");

    for ( int y = 0; y < counter; y++)
    {
        MyFile2 << bigArray[y] << endl;
    }

    MyFile2.close();
    return 0;
}