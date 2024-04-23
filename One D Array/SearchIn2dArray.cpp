#include <bits/stdc++.h>
using namespace std;
// int findrow(vector<int> v, int k, int mi)
// {
//     int i = 0, j = mi - 1;
//     int a = -1;
//     while (i <= j)
//     {
//         int m = (i + j) >> 1;
//         cout<<m<<" ckeck "<<v[m]<<endl;
//         if (v[m] == k)
//         {
//             a = m;
//             break;
//         }
//         else if (v[m] < k)
//             i = m + 1;
//         else
//             j = m - 1;
//     }
//     return a;
// }
// void find(vector<vector<int>> v, int k)
// {
//     int n, m;
//     n = v.size();
//     m = v[0].size();
//     int i, j;
//     i = 0, j = n - 1;
//     int a = -1, b = -1;
//     while (i <= j)
//     {
//         int mid = (i + j) >> 1;

//         if (v[mid][0] <= k && v[mid][m - 1] >= k)
//         {
//             a = mid;
//            b = findrow(v[mid], k, m);
//             break;
//         }
//         else if (v[mid][0] > k)
//             j = mid - 1;
//         else
//             i = mid + 1;
//     }
//     cout<<"The element Find In "<<a<<" "<<b<<endl;
// }
void find(vector<vector<int>> v, int k)
{
    int n, m;
    n = v.size();
    m = v[0].size();
    int i, j;
    i = 0, j = n * m - 1;

    while (i <= j)
    {
        int mid = (i + j) >> 1;
        int r = mid / m;
        int c = mid % m;
        //cout<<v[r][c]<<endl;
        if (v[r][c] == k)
        {
            cout << r << " " << c << endl;
            break;
        }
        else if (v[r][c] < k)
            i = mid + 1;
        else
            j = mid - 1;
    }
}

/// @brief  TC = O(log(n*m))
/// @return 
int main()
{

    vector<vector<int>> v = {{3, 4, 7, 9}, {12, 13, 16, 18}, {20, 21, 23, 29}};
    find(v, 23);
    return 0;
}