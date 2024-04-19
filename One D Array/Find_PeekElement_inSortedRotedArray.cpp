#include <bits/stdc++.h>
using namespace std;
// Find peek element a[i]>a[i-1] && >a[i+1]
// void peek(vector<int> v)
// {
//     int a = -1;
//     int n = v.size();
//     if (v.size() <= 1) cout<<v[0];
//         return;

//     if (v[0] > v[1])
//         a = v[0];

//     if (n >= 2 && v[n - 1] > v[n - 2])a=v[n-1];

//         for (int i = 1; i < n - 1; i++)
//         {
//             if (v[i] > v[i + 1] && v[i] > v[i - 1])
//             {
//                 a = v[i];
//                 break;
//             }
//         }
//     cout << a << endl;
//
void peek(vector<int> v)
{
    int a = -1;
    int n = v.size();

    int l, h, m;
    l = 1;
    h = n - 2;
    if (v.size() == 1){ cout << v[0];
    return;}

    if (n >= 2 && v[n - 1] > v[n - 2]) { cout << v[n - 1] << endl;
    return;}

    while (l <= h)
    {
        
        m = (l + h) / 2;
        int r = m + 1;
        int le = m - 1;
        if (v[m] > v[r] && v[m] > v[le])
        {
            a = v[m];
            break;
        }
        else if (v[m] > v[le])
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    cout << a << endl;
}

int main()
{
    vector<int> v = {4, 5,1,3,4, 6, 7, 2, 4};
    peek(v);
    return 0;
}
