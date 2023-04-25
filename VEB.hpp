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
    public: int Min()
    {
        return min;
    }

    public: VEB(int size)
    {
        this->universalSize = size;
        this->max = -1;
        this->min = -1;

            if(size <= 2)
            {
                this->summary = nullptr;
                this->clusters = vector<VEB*>(0, nullptr);
            }
            else
            {
                int num_clusters = ceil(sqrt(size));
                this->clusters = *(new vector<VEB *>(num_clusters, nullptr));
                this->summary = new VEB(num_clusters);

                for(int i = 0; i < num_clusters; i++)
                {
                    this->clusters[i] = new VEB(num_clusters);
                }
            }
    }
};

//return a True/False on whether or not it found the input integer
bool VEB::Find(VEB *root, int target)
{
    if(root->min > target || target > root->max)
    {
        return false;
    }
    if(root->universalSize <= 2)
    {
        return root->min == target || root->max == target;
    }
    if(root->min == target)
    {
        return true;
    }

    //find index of cluster that would hold the target
    int cluster_index = target / root->clusters.size();

    //calculate target value for next cluster
    int new_target = target - cluster_index * root->clusters.size();

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
    if(root->clusters.size() == 0)
    {
        if(root->min == root->max && root->min == target)
        {
            root->min = -1;
            root->max = -1;
            return;
        }
        if(root->min == target)
        {
            root->min = root->max;
            return;
        }
        root->max = root->min;
        return;
    }

    if(root->min == target)
    {
        int index = root->summary->min;
        min = root->clusters[index]->min + index * root->clusters.size();
        Delete(root->clusters[index], target);
        return;
    }

    int index = target / root->clusters.size();
    int new_target = target % root->clusters.size();
    Delete(root->clusters[index], new_target);

    if(root->clusters[index]->min == -1)
    {
        Delete(root->summary, index);
    }
    
    if(root->max == target)
    {
        if(root->summary->min == -1)
        {
            root->max == root->min;
        }
        else
        {
            index = root->summary->max;
            root->max = root->clusters[index]->max + root->clusters.size() * index;
        }
    }
}