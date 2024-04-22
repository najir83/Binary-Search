#include <bits/stdc++.h>
using namespace std;
// using binary search

void median(vector<int> v, vector<int> ar)
{
    int n, m, mid;
    n = v.size();
    m = ar.size();
    if (n > m)
    {
        median(ar, v);
        return;
    }
    int i, j;
    i = 0;
    j = n;
    int l = (n + m + 1) / 2;
    float an = -1;
    while (i <= j)
    {

        mid = (i + j) >> 1;
        int mid2 = l - mid;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid < n)
            r1 = v[mid];

        if (mid2 < m)
            r2 = ar[mid2];

        if (mid - 1 >= 0)
            l1 = v[mid - 1];

        if (mid2 - 1 >= 0)
            l2 = ar[mid2 - 1];
            
        if (l1 <= r2 && l2 <= r1)
        {
            int a = max(l1, l2);
            int b = min(r1, r2);
            if ((n + m) % 2 == 1)
                an = a;
            else
                an = ((float)a + (float)b) / 2;
            break;
        }
        else if (l1 <= r2)
            i = mid + 1;
        else
            j = mid - 1;
    }
    cout << "The median is " << an << endl;
}

int main()
{
    vector<int> v = {1, 3};
    vector<int> ar = {2};
    median(v, ar);

    return 0;
}