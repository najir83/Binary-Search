#include <bits/stdc++.h>
using namespace std;
// least Capaciy to shifted Packages with in d days
bool isShifted(vector<int> v, int i, int d)
{
    int cnt = 0;
    int sum = 0;
    for (auto it : v)
    {
        sum += it;
        if (sum == i)
        {
            cnt++;
            sum = 0;
        }
        else if (sum > i)
        {
            cnt++;
            sum = it;
        }
    }
    if (sum <= i)
    {
        cnt++;
    }
    return cnt <= d;
}
int sumi(vector<int> v)
{
    int sum = 0;
    for (auto it : v)
        sum += it;

    return sum;
}
void leastCapacity(vector<int> v, int d)
{
    int h = sumi(v);
    int a = -1;
    int l, m;
    l = *(max_element(v.begin(), v.end()));
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (isShifted(v, m, d))
        {
            a = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << a << endl;
}
// T C = O(log(sum-mx+)*N)

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    leastCapacity(v, days);

    return 0;
}