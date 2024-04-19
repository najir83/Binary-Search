#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    for (auto it : v)
        cout << it << " ";

    cout << endl;
}
// int countDistinct(vector<int> nums, int k, int p)
// {
//     set<vector<int>> st;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         int cnt = 0;
//         vector<int> v;
//         for (int j = i; j <n; j++)
//         {
//             v.push_back(nums[j]);
//             if (nums[j] % p == 0)
//             {
//                 cnt++;
//                 if (cnt > k)
//                     break;
//             }

//             print(v);
//             st.insert(v);
//         }
//     }
//     return st.size();
// }
int c = 0;
void print(vector<int> v, int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        cout << c++ << " : ";
        for (int j = i; j <= r; j++)
        {
            cout << v[j] << " ";
        }
        cout << endl;
    }
}
int countDistinct(vector<int> v, int k, int p)
{
    int n = v.size();
    int l, r, cnt;
    l = r = cnt = 0;
    int chk = 0;
    unordered_map<int, int> m;
    while (r < n)
    {

        m[v[r]]++;
        if (v[r] % p == 0)
        {
            chk++;
        }
        while (chk > k)
        {
            m[v[l]]--;
            if (m[v[l]] == 0)
            {
                m.erase(v[l]);
            }
            if (v[l] % p == 0)
            {
                chk--;
            }
            l++;
        }
        int c = 0;
        if (m[v[r]] != 1)
        {
            c = -1;
        }
        cnt += (r - l + 1 + c);
        print(v, l, r);
        r++;
    }
    return cnt;
}
int main()
{
    vector<int> v = {1,2,3,4};
    int k = 4, p = 1;
    cout << "The no is " << countDistinct(v, k, p);

    return 0;
}