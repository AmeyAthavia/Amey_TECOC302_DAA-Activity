#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FF first
#define SS second
#define M_P make_pair
#define MOD 1000000007

lli arr_1[100010];
int arr_2[10000];
lli arr_3[1010][9000];
vector<lli> v;
int xx=0;
int yy[10000];

void Prime_xor (){
    for(int i=2;i<=9000;i++ ){
        if(!yy[i]) 
            for(int j=2;j*i<9000;j++){
                yy[j*i]=1;
            }
      
    }
}
 


lli  solve(int idx,int xr){
    if(idx==xx && xr==0) return 1;
        else if(idx==xx) return 0; 
    if(arr_3[idx][xr]!=-1) return arr_3[idx][xr];
    else{
        int val=v[idx];
        int count=arr_2[val];
        int ev=count/2;
        int odd=count/2;
        if(count%2==1) odd++;
        ev++;
        int xrr=xr xor val;
        arr_3[idx][xr]=((1ll*(solve(idx+1,xrr)*odd))%MOD+((1ll*(solve(idx+1,xr)*ev))%MOD))%MOD;
        return arr_3[idx][xr];
   }
}

int main(){
    Prime_xor();
    int t;
    cin>>t;
    while(t--){
        memset(arr_2,0,sizeof arr_2);
        memset(arr_3,-1,sizeof arr_3);
        int n;
        cin>>n;
    
        v.clear();
        for(int  i=0;i<n;i++){
            cin>>arr_1[i];
            if(arr_2[arr_1[i]]==0) v.push_back(arr_1[i]);
            arr_2[arr_1[i]]++;
        }
    
        lli ans=0;
        xx=v.size();
     
        for(int i=2;i<=8192;i++){
            if(!yy[i]){
         //  cout<<" check for "<<i<<endl;
            ans=(ans+solve(0,i))%MOD;
            }   
        }
    cout<<ans<<endl;
    }
}
