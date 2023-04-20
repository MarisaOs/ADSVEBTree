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
    int arr[100];

    srand((unsigned)time(NULL));

    while( counter != 100)
    {
        num = rand()%250000;
        for ( int x = 0; x < counter; x++)
        {
            if ( num == arr[x])
            {
                num = rand()%250000;
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

    int bigArray[30000];
    counter = 0;
    while( counter != 30000)
    {
        num = rand() % 250000;
        for ( int x = 0; x < counter; x++)
        {
            if ( num == bigArray[x])
            {
                num = rand() % 250000;
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