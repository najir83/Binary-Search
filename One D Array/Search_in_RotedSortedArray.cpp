#include <bits\stdc++.h>
using namespace std;
// Search in rotated sorted Array
void search(vector<int> v, int tg)
{
    int n = v.size();
    int l, h, m;
    l = 0;
    h = n - 1;
    int ans = -1;
    while (l <= h)
    {
        m = (l + h) / 2;
        cout<<"Chk "<<m<<endl;
        if (v[m] == tg)
        {
            ans = m;
            break;
        }
        else if (v[m] >= v[l])
        {
            if (tg >= v[l] && tg < v[m])
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }//<========<>==?==<>==?===<>=========>
        else
        {
            if (v[h] >= tg && v[m] < tg)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
    }
    cout << "The Index of " << tg << " = " << ans << endl;
}
//<========<>==?==<>==?===<>=========>
int main()
{
    vector<int> v = {4,5,6,1,2,3,4};
    for(auto it:v)cout<<it<<" ";

    cout<<endl;
    int tg;
    int op;
    do
    {
        cout<<"Enter tg : ";
        cin >> tg;

        search(v, tg);
        cin >> op;
    } while (op == 1);
    return 0;
}
