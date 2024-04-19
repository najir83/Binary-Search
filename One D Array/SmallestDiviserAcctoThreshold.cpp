#include <bits/stdc++.h>
using namespace std;
// Finf the smallest Diviser given a arr and a threshold value
bool isDiviser(vector<int> v, int i, int th)
{
    int cnt = 0;
    for (auto it : v)
    {
        int m = (it / i);
        if (i * m != it)
        {
            m += 1;
        }
        cnt += m;
    }
    return cnt <= th;
}
void SmallestDivier(vector<int> v, int th)
{
    int n = v.size();
    int a = -1;
    int l, h, m;
    l = 1;
    h = *(max_element(v.begin(), v.end()));
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (isDiviser(v, m, th))
        {
            h = m - 1;
            a = m;
        }
        else
        {
            l = m + 1;
        }
    }
    cout<<a<<endl;
}
//TIME COMPLEXITY O(N*log(max(v)))
int main()
{
    vector<int> v = {1, 2, 5, 9};
    int th = 6;
    SmallestDivier(v, th);

    return 0;
}