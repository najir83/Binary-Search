#include <bits/stdc++.h>
using namespace std;
// Koko Eating bananas(read the documentation in note for understanding)
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
int eating(vector<int> v, int i, int h)
{
    int cnt = 0;
    for (auto it : v)
    {
        int val = it / i;
        if (val * i != it)
        {
            val += 1;
        }
        cnt += val;
        if (cnt > h)
        {
            return h + 1;
        }
    }

    return cnt;
}

void K_sValue(vector<int> v, int h)
{
    int r = maxi(v);
    int a = -1;
    int l, i;
    l = 0;
    while (l <= r)
    {
        i = (l + r) / 2;

        int val = eating(v, i, h);
        if (val > h)
        {

            l = i + 1;
        }
        else
        {
            a = i;
            r = i - 1;
        }
    }
    cout << a << endl;
}

int main()
{
    vector<int> v = {3, 6, 7, 11};
    int h = 8;
    K_sValue(v, h);
    

    return 0;
}