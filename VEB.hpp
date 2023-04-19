//This is where we have the Van Emde Boas Tree actually created
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class VEB
{
    int universalSize;
    int max;
    int min;
    vector<VEB*> clusters;
    VEB* summary;

    bool Find(VEB *root, int target);
    VEB* Search(VEB *root, int target);
    void Insert(VEB *root, int target);
    void Delete(VEB *root, int target);

    VEB(int size)
    {
        universalSize = size;
        int max = -1;
        int min = -1;

        if(size <= 2)
        {
            summary = nullptr;
            clusters = vector<VEB*>(0, nullptr);
        }
        else
        {
            int num_clusters = ceil(sqrt(size));
            clusters = vector<VEB *>(num_clusters, nullptr);

            for(int i = 0; i < num_clusters; i++)
            {
                clusters[i] = new VEB(ceil(sqrt(num_clusters)));
            }
        }
    }
};

//return a True/False on whether or not it found the input integer
bool VEB::Find(VEB *root, int target)
{

}

//private function that works like find but returns a VEB instead
//don't use in the main program
VEB *VEB::Search(VEB *root, int target)
{

}

//put the integer into the VEB
void VEB::Insert(VEB *root, int target)
{

}

//delete the integer from the VEB
void VEB::Delete(VEB *root, int target)
{
    
}