#include <bits/stdc++.h>
using namespace std;
// Nth root of integer
// brute force O(n)
// void nrt(int n, int r)
// {
//     int a = -1;
//     for (int i = 0; i <= n; i++)
//     {
//         int tem = i;
//         for (int j = 1; j < r; j++)
//         {
//             tem *= i;
//         }
//         if (tem == n)
//         {
//             a = i;
//             break;
//         }
//         else if (tem > n)
//         {
//             break;
//         }
//     }
//     cout << a << endl;
// }
// func of mid^r

void nrt(int n, int r)
{
    int a = -1;
    int l, h, m;
    l = 0;
    h = n;
    while (l <= h)
    {
        m = (l + h) / 2;

        long long ans = 1;
        for (int i = 1; i <= r; i++)
        {
            ans = ans * m;
        }
        if (ans == n)
        {
            a = m;
            break;
        }
        else if (ans > n)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << a << endl;
}

int main()
{
    nrt(27, 3);
    return 0;
}