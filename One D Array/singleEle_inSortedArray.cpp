#include <bits/stdc++.h>
using namespace std;
// single element in sorted array
void single(vector<int> v)
{
    int l, h, m;
    l = 1;
    int a = -1;
    h = v.size() - 2;
    if (v.size() == 1)
    {
        cout << v[0] << endl;
        return;
    }
    if (v[0] != v[1])
    {
        cout << v[0];
        return;
    }
    if (v[v.size() - 1] != v[v.size() - 2])
        cout << v[v.size() - 1];
    return;

    while (l <= h)
    {
        m = (l + h) / 2;
        if (v[m] != v[m - 1] && v[m] != v[m + 1])
        {
            a = v[m];
            break;
        }
        else if ((m % 2 != 0 && v[m] == v[m - 1]) || (m % 2 == 0 && v[m] == v[m + 1]))
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
    vector<int> v = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    single(v);

    return 0;
}