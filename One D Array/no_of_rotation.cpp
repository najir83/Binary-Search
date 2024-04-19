#include <bits/stdc++.h>
using namespace std;
// How many times a arr is rotated
int minEl(vector<int> v){
    int ind = -1;
    int mn = INT_MAX;
    int l, h, m;
    l = 0;
    h = v.size() - 1;
    while (l <= h)
    {
        m = (l + h) / 2;
        mn = min(v[m], mn);
        if (mn == v[m])
            ind = m;

        if (v[l] <= v[m])
        {
            mn = min(v[l], mn);
            if (mn == v[m])
                ind = l;

            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    return ind;
}
void rotation(vector<int> v)
{
    cout << minEl(v) << endl;
}
int main()
{
    vector<int> v = {3, 4, 5, 1, 2};
    rotation(v);
    return 0;
}