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

    //basic VEB contructor
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
    //if put of bounds of held values return false
    if(root->min > target || target > root->max)
    {
        return false;
    }
    //if leaf node return whether it is there or not
    if(root->universalSize <= 2)
    {
        return root->min == target || root->max == target;
    }
    //if at any time min is the target return true
    if(root->min == target)
    {
        return true;
    }

    //This means that target is not min and is potentially further down the tree
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
    //if node does not have min target is new min
    if(root->min == -1)
    {
        root->min = target;
        root->max = target;
        return;
    }

    //else
    //if current min is bigger than target swap them and continue
    if(root->min > target)
    {
        int temp = target;
        target = root->min;
        root->min = temp;
    }

    //if target is greater than max replace max with target and continue
    if(root->max < target)
    {
        root->max = target;
    }

    //if this isn't a leaf node of the VEB tree
    if(root->clusters.size() != 0)
    {
        //calculate index and new target val for Insert()
        int index = floor(target / root->clusters.size());
        int new_target = target % root->clusters.size();
        //Go further in the tree and insert val
        Insert(root->clusters[index], new_target);
        //if this was the first value to be inserted below the tree update summary to include this
        if(root->clusters[index]->min == root->clusters[index]->max)
        {
            Insert(root->summary, index);
        }
    }
}

//delete the integer from the VEB
void VEB::Delete(VEB *root, int target)
{
    //if it is a VEB() of size 2 or less
    if(root->clusters.size() == 0)
    {
        //delete last value in VEB node
        if(root->min == root->max && root->min == target)
        {
            root->min = -1;
            root->max = -1;
            return;
        }
        //delete min
        if(root->min == target)
        {
            root->min = root->max;
            return;
        }
        //delete max
        root->max = root->min;
        return;
    }

    //else
    //if min is target
    if(root->min == target)
    {
        //find next smallest value and make min equal that
        int index = root->summary->min;
        min = root->clusters[index]->min + index * root->clusters.size();
        //delete new min from it's old spot
        Delete(root->clusters[index], target);
        return;
    }

    //else
    //calculate new values needed for VEB progression
    int index = target / root->clusters.size();
    int new_target = target % root->clusters.size();
    //go further in VEB tree to find value
    Delete(root->clusters[index], new_target);

    //if what I just deleted was the last one in the below tree update summary
    if(root->clusters[index]->min == -1)
    {
        Delete(root->summary, index);
    }

    //if the target was the max fix max
    if(root->max == target)
    {
        //if max was the last value below this node max = min now
        if(root->summary->min == -1)
        {
            root->max == root->min;
        }
        else
        {
            //max equals next closest max
            index = root->summary->max;
            root->max = root->clusters[index]->max + root->clusters.size() * index;
        }
    }
}