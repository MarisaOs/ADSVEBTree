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

    public: bool Find(VEB *root, int target);
    public: void Insert(VEB *root, int target);
    public: void Delete(VEB *root, int target);

    public: VEB(int size)
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
    cout << "Target = " << target << endl;

    if(root->min > target || target > root->max)
    {
        return false;
    }
    if(root->universalSize <= 2)
    {
        return root->min == target || root->max == target;
    }

    //find index of cluster that would hold the target
    int cluster_index = target / root->clusters.size();

    //calculate target value for next cluster
    int new_target = target - root->clusters.size();

    //recursively call Find and return truth value
    return Find(root->clusters[cluster_index], new_target);
}

//put the integer into the VEB
void VEB::Insert(VEB *root, int target)
{
    if(root->min == -1)
    {
        root->min = target;
        root->max = target;
        return;
    }

    if(root->min > target)
    {
        int temp = target;
        target = root->min;
        root->min = temp;
    }

    if(root->max < target)
    {
        root->max = target;
    }

    if(root->clusters.size() != 0)
    {
        int index = floor(target / root->clusters.size());
        int new_target = target % root->clusters.size();
        Insert(root->clusters[index], new_target);
        if(root->clusters[index]->min == root->clusters[index]->max)
        {
            Insert(root->summary, index);
        }
    }
}

//delete the integer from the VEB
void VEB::Delete(VEB *root, int target)
{
    if(root->min == root->max)
    {
        root->min = -1;
        root->max = -1;
        return;
    }

    if(target == root->min)
    {
        int hi = root->summary->min * root->clusters.size();
        int j = root->summary->min;
        target = hi + root->clusters[j]->min;
        root->min = target;
    }

    if(root->clusters.size() != 0)
    {
        int i = floor(target / root->clusters.size());
        int lo = target % root->clusters.size();
        Delete(root->clusters[i], lo);
        if(root->clusters[i]->min = -1)
        {
            Delete(root->summary, i);
        }
        if(target == root->max)
        {
            if(root->summary->min == -1)
            {
                root->max = root->min;
            }
            else
            {
                int hi = root->summary->max * root->clusters.size();
                int j = root->summary->max;
                root->max = hi + root->clusters[j]->max;
            }
        }
    }
}