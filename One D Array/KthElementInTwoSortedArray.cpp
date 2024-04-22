#include <bits/stdc++.h>
using namespace std;
// U are given two sorted array and a k .. return the kth element
void KthElement(vector<int> v, vector<int> ar, int k)
{
    int n = v.size();
    int m = ar.size();
    if (n > m)
    {
        KthElement(ar, v, k);
        return;
    }
    int mid, i, j, l;
    l = k;
   i = max(0,k-m); // if k=7 and m=5 then if u take 0 from v then how u could maneged 7 ele from 5 is is not !
    j =min(k,n);// if u get k=2 where n=2728 so you should take atmost 2 from 1st
    int an = -1;
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
            an = a;
            break;
        }
        else if (l1 <= r2)
            i = mid + 1;
        else
            j = mid - 1;
    }
    cout << "KTH ELEment : " << an;
}

int main()
{
    vector<int>v={4,4,4,4,6,6,8,8,8,8,8,8};
    vector<int>ar={5,5,5,5,7,7,9,9,9,9,9,9};
    KthElement(v,ar,2);

    return 0;
}

