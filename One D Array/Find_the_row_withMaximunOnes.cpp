#include<bits/stdc++.h>
using namespace std;
//brute force
// void maxiOnes(vector<vector<int>>v){
//     int ind=-1,fre=0;
//     for(int i=0;i<v.size();i++){
//         int cnt=0;
//         for(auto it:v[i]){
//             if(it==1)cnt++;
//         }
//         if(cnt>fre){
//             fre=cnt;
//             ind=i;
//         }
//     }
//     cout<<ind<<" "<<fre<<endl;

// }
//optimal
void maxiOnes(vector<vector<int>>v){
    int ind=-1,fre=0;
    for(auto& it:v)sort(it.begin(),it.end());
    
    for(int i=0;i<v.size();i++){
        int cnt=0;
        int j=0,k=v[0].size();
        while(j<=k){

            int mid=(j+k)>>1;
            if(v[i][mid]==0)j=mid+1;
            else k=mid-1;
        }
        cout<<" j ="<<j<<endl;
        cnt=v[0].size()-j;
        if(cnt>fre){
            fre=cnt;
            ind=i;
        }
    }
    vector<int>a(2);
    a[0]=ind;
    a[1]=fre;
    cout<<a[0]<<" "<<a[1]<<endl;

}
//TC =O(n*log(m))
int main(){
vector<vector<int>>v={{0,1},{1,0}};//{{0,0,1,1,1},{0,0,0,0,0},{0,1,1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
maxiOnes(v);

return 0;
}