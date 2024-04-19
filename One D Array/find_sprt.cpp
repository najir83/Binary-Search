#include <bits/stdc++.h>
using namespace std;
// find sqrt of int (just integer value skep the floating value)
// brute force TC=O(sqrt(n))
// void sqr(int n)
// {
//     int a = 0;
//     for (int i = 0; i<=n; i++)
//     {
//         if (i * i > n)
//         {
//             break;
//         }
//         a = i;
//     }
//     cout << a << endl;
// }
void sqr(int n)
{
    int a = 0;
    int l, h;
    long long  m;
    l = 0, h = n;
    int cnt = 0;
    while (l <= h)
    {
        cnt++;
        m = ((long)l+(long)h)/2;
        
        if ((m * m) <= n)
        {
            a = m;
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }
    cout << sqrt(n) << " " << a << endl;
    cout << "Loop runs for : " << cnt << " times" << endl;
}

int main()
{
    int n, op;
    do
    {
        cout << "Enter the number : ";
        cin >> n;
        sqr(n);
        cin >> op;
    } while (op == 1);
    return 0;
}