#include <bits/stdc++.h>
using namespace std;
// Finding the kth missing element

// T C O(n)
// use one more brute ha ha ha
void missing_element(vector<int> v, int k)
{
    for (auto it : v)
    {
        if(it<=k)k++;

        else{
            break;
        }
    }
    cout<<k<<endl;
}
void missing_element2(vector<int> v, int k)
{
    int l,h,m;
    l=0,h=v.size()-1;
    while(l<=h){
        m=l+(h-l)/2;
        if(v[m]-(m-l+1)<=k){
            k+=(m-l+1);
            l=m+1;
        }
        else{
            h=m-1;

        }
    }
    cout<<k<<endl;

}
int main()
{
    vector<int> v = {2, 3, 4, 7, 11};
    int k = 5;
    missing_element2(v, k);
    return 0;
}