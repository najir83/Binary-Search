#include <bits/stdc++.h>
using namespace std;
// median in 2d
//  void Median(vector<vector<int>>v){
//  int n,m;
//  n=v.size();
//  m=v[0].size();
//  int chk=((n*m)/2)+1;

// priority_queue<int>pq;
// for(int i=0;i<n;i++){
//     for(auto it:v[i]){
//         cout<<"Ele in "<<it<<" ";
//         if(chk!=0){
//             pq.push(it);
//             chk--;
//         }
//         else{
//             if(pq.top()>it){
//                 cout<<"Pop val : "<<pq.top()<<endl;
//                 pq.pop();
//                 pq.push(it);
//             }

//         }
//         cout<<" size "<<pq.size()<<" ";
//     }
//     cout<<"\n ans "<<pq.top();
// }

// Optimization

pair<int, int> mk(vector<vector<int>> v)
{
    int m = v[0].size();
    int l = v[0][0], h = v[0][m - 1];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i][0] < l)
            l = v[i][0];

        if (v[i][m - 1] > h)
            h = v[i][m - 1];
    }
    return {l, h};
}
int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}
int findMedian(vector<vector<int>> &A)
{
    pair<int, int> p = mk(A);
    int low = p.first;
    int high = p.second;
    int n = A.size();
    int m = A[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(A[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{

    vector<vector<int>> arr = {{1, 3, 8},
                               {2, 3, 4},
                               {1, 2, 5}};
   cout<<findMedian(arr);
    return 0;
}