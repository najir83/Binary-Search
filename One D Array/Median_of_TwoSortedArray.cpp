#include <bits/stdc++.h>
using namespace std;
void print(vector<int>v){
    for(auto it: v)cout<<it<<" ";

    cout<<endl;
}
// find the median of two sorted array
// int merging(vector<int> &v, vector<int> arr)
// {
//     int n = v.size();
//     int m = arr.size();
//     int i, j;
//     i = j = 0;
//     //int k = 0;
//     vector<int> ans;
//     while (i < n && j < m)
//     {
//         if (v[i] < arr[j])
//         {
//             ans.push_back(v[i++]);
//         }
//         else
//         {
//             ans.push_back(arr[j++]);
//         }
//     }
//     while (i < n)
//     {
//         ans.push_back(v[i++]);
//     }
//     while (j < m)
//     {
//         ans.push_back(arr[j++]);
//     }
//     print(ans);
//     if((n+m)%2==0){
//         int a=m+n;
//         cout<<a<<endl;

//         return  (ans[(a/2)-1]+ans[a/2])/2;
//     }
//     else{
//         return ans[((m+n)/2)];
//     }
//  TC=O(n=m)   SC: O(n+m)}
//optimal 
 pair<int,int> merging(vector<int> &v, vector<int> arr)
{
    int n = v.size();
    int m = arr.size();
    int tg=1+(n+m)/2;
    int i, j;
    i = j = 0;
    int k = 0;
    int root,pre;
    while(i<n && j<m){
        pre=root;
if(v[i]<arr[j]){
    
    root=v[i];
    i++;
}
else{root=arr[j];
j++;

}
k++;
cout<<pre<<" "<<root<<" k= "<<k<<endl; 
if(k==tg) return {pre,root};


    }
    int ind;
    if(i<n){
        ind=tg-k+i-1;
        if(ind!=0){
        pre=max(root,v[ind-1]);
        }
        else{
            pre=root;
        }
        root=v[ind];
        
    }
    else{
        ind=tg-k+j-1;
        if(ind!=0){
        pre=max(root,arr[ind-1]);}
        else{ pre=root;}
        root=arr[ind];
    }
    return {pre,root};

}
void median(vector<int> v, vector<int> ar)
{
    cout<<"The median will be ";
    pair<int,int>p=merging(v, ar);
    cout<<p.first<<" "<<p.second;
}

int main()
{
    vector<int> v = {1,3,4,7,10,12};
    vector<int> ar ={2,3,6,15};
    print(v);
    print(ar);
    median(v, ar);

    return 0;
}