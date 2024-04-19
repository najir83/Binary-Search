#include <bits/stdc++.h>
using namespace std;
// Minimum no of days to make m boukets

bool chkBouques(vector<int> v, int m, int k, int d)
{
    int cntM = 0;
    int cnt = 0;
    for (auto it : v)
    {
        //  cout<<d/it<<" ";
        if ((d / it) >= 1)
        {
            cnt++;
            if (cnt == k)
            {
                cntM++;
                if (cntM >= m)
                    return true;

                cnt = 0;
            }
        }
        else
        {
            cnt = 0;
        }
    }
    return false;
}
int maxi(vector<int> v)
{
    int mx = INT_MIN;
    for (auto it : v)
    {
        if (it > mx)
            mx = it;
    }
    return mx;
}
// TC : O(n*max(v))
// void BouquesDays(vector<int> v, int m, int k)
// {
//     int a=-1;
//     int n=maxi(v);
//     for(int i=1;i<n;i++){
//         if(chkBouques(v,m,k,i)){
//             a=i;
//             break;
//         }
//     }
//     cout<<a<<endl;
// }

void BouquesDays(vector<int> v, int m, int k)
{
    int a = -1;
    if (m * k > v.size())
    {
        cout << a << endl;
        return;
    }
    int l, h, mid;
    h = maxi(v);
    l = 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (chkBouques(v, m, k, mid))
        {
            h = mid - 1;
            a = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << a << endl;
}

int main()
{
    vector<int> v = {1, 10, 3, 10, 2};
    int k, m;
    m = 3, k = 2;
    BouquesDays(v, m, k);
    return 0;
}