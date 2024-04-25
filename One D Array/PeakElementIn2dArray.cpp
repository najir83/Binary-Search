#include <bits/stdc++.h>
using namespace std;

// Peak element in 2d array

int maxE(vector<vector<int>> &v, int md, int n)
{
    int ind = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i][md] > v[ind][md])
            ind = i;
    }
    return ind;
}


vector<int> findPeakGrid(vector<vector<int>> &v)
{
    int n = v.size(), m = v[0].size();
    int l = 0, r = m - 1;
    while (l <= r)
    {
        int md = l + (r - l) / 2;
        int ind = maxE(v, md, n);

        int left = (md != 0) ? v[ind][md - 1] : -1;
        int right = (md != m - 1) ? v[ind][md + 1] : -1;
        if (v[ind][md] > left && v[ind][md] > right){
            cout<<ind<<" "<<md;
            return {ind, md};
        }
        else if (v[ind][md] > left)
            l = md + 1;
        else
            r = md - 1;
    }
    return {-1, -1};
}

int main()
{
    vector<vector<int>> v = {
        {1, 4},
        {3, 2},
    };

    findPeakGrid(v);

    return 0;
}