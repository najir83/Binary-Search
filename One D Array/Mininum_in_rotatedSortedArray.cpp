#include <bits/stdc++.h>
using namespace std;
void minEle(vector<int> v)
{
    int mn = INT_MAX;
    int l, h, m;
    l=0;
    h=v.size()-1;
    while (l <= h)
    {
        m = (l + h) / 2;
        mn = min(v[m], mn);
        if (v[l] <= v[m])
        {
            mn = min(v[l], mn);
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    cout<<"Minimun Element is "<<mn<<endl;
}

int main()
{
    vector<int> v = {4,5,7,0,1};
minEle(v);
    return 0;
}
