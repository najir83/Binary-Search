#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.
*/
bool istrue(vector<int> v, int i, int k)
{
    int chk = 1;
    int sum = 0;
    for (auto it : v)
    {
        if (sum + it <= i)
        {
            sum += it;
        }
        else
        {
            
            sum = it;
            chk++;
            if (chk > k)
                return false;
        }
    }
    
    return chk == k;
}
void minimised_largest_sum(vector<int> v, int k)
{
    int l, h, m;
    m=-1;
    l = *(max_element(v.begin(), v.end()));
    h=accumulate(v.begin(),v.end(),0);
    while (l<=h)
    {
        if (istrue(v, l, k))
        { m=l;
           
            break;
        }
        l++;
    }
    cout <<"the answer will be "<< m<< endl;
}
//use binary search same as book allocate
int main()
{
    vector<int>v={2,3,1,1,1,1,1};
    int k=5;
    minimised_largest_sum(v,k);

    return 0;
}