#include <bits/stdc++.h>
using namespace std;
// Search in 2 d matrix where every row and coloum wise sorted
//  int chk(vector<vector<int>>v,int i,int k){
//      int l=0,r=v[0].size()-1;
//      while(l<=r){

//         int m=l+(r-l)/2;
//         cout<<" Run for "<<m<<" ";

//         if(v[i][m]==k)return m;
//         else if(v[i][m]<k)l=m+1;
//         else r=m-1;
//     }
//     return -1;
// }
// void find(vector<vector<int>>v,int k){
//     int n,m;
//     n=v.size();
//     m=v[0].size();
//     int i,j;
//     i=0,j=n-1;
//     int a=-1,b=-1;
//     for(int i=0;i<n;i++){
//         cout<<" runs for "<<i<<" ";
//         if(v[i][0]<=k && v[i][m-1]>=k){
//              b=chk(v,i,k);
//              a=i;
//              if(b!=-1)break;
//         }
//     }
//     cout<<"The position will be :"<<a<<" , "<<b<<endl;
// }

// T C =O(n*log(m))
void find(vector<vector<int>> v, int k)
{
    int n, m;
    n = v.size();
    m = v[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {

        if (v[i][j] == k)
        {
            cout << i << " " << j << endl;
            break;
        }
        else if (v[i][j] > k)
            j--;
        else
            i++;
    }
}

int main()
{
    vector<vector<int>> v = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    find(v, 10);
    return 0;
}