#include <bits/stdc++.h>
using namespace std;
bool shouldPlaced(vector<int> v, int dist, int c)
{
    int cnt = c - 1;
    int preCow = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - v[preCow] >= dist)
        {
            preCow = i;
            cnt--;
            if (cnt == 0)
                return true;
        }
    }
    return false;
}
// Aggresive crows
void max_of_min(vector<int> v, int c)
{
    int a = -1;
    sort(v.begin(), v.end());
    int h = v[v.size() - 1];
    int l, m;
    l = 1;
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (shouldPlaced(v, m, c))
        {
            l = m + 1;
            a = m;
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
    vector<int> cordinate = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    max_of_min(cordinate, cows);
    return 0;
}