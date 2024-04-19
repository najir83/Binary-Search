#include <bits/stdc++.h>
using namespace std;
// Book allocation Question
// brute force
/*bool isallocated(vector<int> v, int p, int s)
{
    int sum = 0;
    int cnt = 1;
    for (auto it : v)
    {
        sum += it;
        if (sum == p)
        {
            cnt++;

            sum = 0;
        }
        else if (sum > p)
        {
            sum = it;
            cnt++;
        }
        if (cnt > s)
            return false;
    }
    return true;
}*
int max_extra(vector<int> v, int ex)
{
    int l = 0;
    int sum = 0;
    for (int i = 0; i <= ex; i++)
    {
        sum += v[i];
    }
    int r = ex + 1;
    while (r < v.size())
    {
        sum = max(sum, sum + v[r] - v[l]);
        r++;
        l++;
    }
    return sum;
}
void minPages(vector<int> v, int s)
{
    if (v.size() < s)
    {
        cout << "Not possible";
        return;
    }
    int l, h, m;
    h = max_extra(v, v.size() - s);
    m = -1;
    l = *(max_element(v.begin(), v.end()));
    while (l <= h)
    {
        if (isallocated(v, l, s))
        {
            m = l;
            cout << l << " ";
        }
        l++;
    }
    cout << m << endl;
}*/
// binary search
bool isallocated(vector<int> v, int p, int s)
{
    int sum = 0;
    int cnt = 1;
    for (auto it : v)
    {
        if (sum + it <= p)
        {
            sum += it;
        }
        else
        {
            cnt++;
            sum = it;
            if (cnt > s)
                return false;
        }
    }

    return cnt <= s;
}
int sk(vector<int> v)
{
    int sum = 0;
    for (auto it : v)
        sum += it;

    return sum;
}

int minPages(vector<int> &v, int n, int m)
{
    if (n < m)
    {
        // cout << "Not possible";
        return -1;
    }
    int l, h, mid;
    h = sk(v);
    mid = -1;
    int a = -1;
    l = *(max_element(v.begin(), v.end()));
    while (l <= h)
    {

        mid = l + (h - l) / 2;
        if (isallocated(v, mid, m))
        {
            h = mid - 1;
            //  cout<<l<<" ";
        }
        else
        {

            l = mid + 1;
        }
    }
    return l;//because of opposite polarity
}

int main()
{
    vector<int> pages = {25, 46, 28, 49, 24};
    int stud = 4;
   cout<< minPages(pages,pages.size(), stud);
    return 0;
}