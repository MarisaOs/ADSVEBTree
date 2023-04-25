//This will be where we code the problem solution
//trying something

#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "VEB.hpp"

using namespace std;

int main()
{
    int nonsense = 0;
    VEB* VebTree = new VEB(256);

    string UserInput = "";
    int UserKey = 0;
    int NumberOfIDs = 0;

   //To start out, have 100 unique IDS in the database
    for (int i = 0; i <= 100; i++)
    {
        VebTree->Insert(VebTree, i);
    }
   
    //Main menu
    cout << "==============================================" << endl;
    cout << "              Student ID Database" << endl;
    cout << "==============================================" << endl;
    cout << "Options:" << endl;
    cout << "            I- Insert ID" << endl;
    cout << "            D- Delete ID" << endl;
    cout << "            F- Find if ID exists" << endl;
    cout << "            X- Exit Database" << endl;
    
    //Grab user choice
    cout << "User choice:";
    cin >> UserInput;
    //While the user doesnt quit, run the selected menu options
    while (UserInput != "X")
    {
        //Insert ID
        if (UserInput == "I")
        {
            //Grab ID from user
            cout << "Insert new ID: ";
            cin >> UserKey;
   
            if (VebTree->Find(VebTree, UserKey))
            {
                //Prevent duplicate keys
                cout << "ID: " << UserKey << " already exists in the database";
            }
            else
            {
                //Else insert the key
                VebTree->Insert(VebTree, UserKey);
                cout << UserKey << " has been added to the database";
            }         
        }
        //Delete ID
        if (UserInput == "D")
        {
            cout << "ID you want to delete from database: ";
            cin >> UserKey;
            if (VebTree->Find(VebTree, UserKey))
            {
                VebTree->Delete(VebTree, UserKey);
                cout << "ID: " << UserKey << " has been deleted from the database";
            }
            else
            {
                cout << "ID: " << UserKey << " does not exist in the database";
            }
            
        }
        //Find ID
        if (UserInput == "F")
        {
            cout << "ID search: ";
            cin >> UserKey;

            if (VebTree->Find(VebTree, UserKey))
            {
                cout << "ID: " << UserKey << " exists in the database";
            }
            else
            {
                cout << "ID: " << UserKey << " does not exist in the database";
            }
        }

        cout << endl << "----------------------------------------------" << endl;
        cout << "==============================================" << endl;
        cout << "              Student ID Database" << endl;
        cout << "==============================================" << endl;
        cout << "Options:" << endl;
        cout << "            I- Insert ID" << endl;
        cout << "            D- Delete ID" << endl;
        cout << "            F- Find if ID exists" << endl;
        cout << "            X- Exit Database" << endl;

        cout << "User choice:";
        cin >> UserInput;
    }

    cout << "----------------------------------------------";
    cout << endl << "Exiting database" << endl;

}
