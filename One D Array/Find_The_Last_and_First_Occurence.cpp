#include <bits/stdc++.h>
using namespace std;
// find the first and last occurence
// Brute force
/*void anints(vector<int> v, int x)
{
    int i, j;
    i = j = -1;
    for (int k = 0; k < v.size(); k++)
    {
        if (v[k] == x)
        {
            if (i == -1)
            {
                i = k;
                j = k;
            }
            else
            {
                j = k;
            }
        }
    }
    cout << i << " " << j << endl;
    //TC =O(n)
}
*/

// Batter
int lower(vector<int> v, int x)
{
    int n = v.size();
    int i, j;
    i = 0;
    j = n - 1;
    int m;
    int ans = -1;

    while (i <= j)
    {
        m = (i + j) / 2;
        if (v[m] >= x)
        { ans=m;
            j = m - 1;
        }
        else
        {
            i = m + 1;
        }
    }
    return ans;
}
int upper(vector<int> v, int x)
{
    int n = v.size();
    int i, j;
    i = 0;
    j = n - 1;
    int m;
    int ans = -1;

    while (i <= j)
    {
        m = (i + j) / 2;
        if (v[m] > x)
        {
            ans=m;
            j = m - 1;
        }
        else
        {
            i = m + 1;
        }
    }
    return ans;
}
void occurence(vector<int> v, int x)
{
    int a=lower(v, x);
    if(a==-1 || v[a]!=x){
        cout<<-1<<" "<<-1<<endl;
        return ;
    }
    
   /// cout << a << " " << lower(v, x+1) -1<< endl; optimal
   cout << a << " " << upper(v, x) -1<< endl;
}
int main()
{
    vector<int> v = {2, 4, 6, 8, 9, 9, 9, 10};
    int x = 6;
    //  ans(v, x);
    occurence(v, x);
    return 0;
}
