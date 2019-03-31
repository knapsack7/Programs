//See Tushars Dp Optimal Game Strategy video
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
pair<ll,ll> dp[31][31];

void filldp(ll *arr,ll n){

for(ll i=1;i<=n;++i){
    dp[i][i].first=arr[i];
    dp[i][i].second=0;
}
for(ll k=0;k<n;++k){
    for(ll i=1,j=i+k;j<=n;++i,++j){
        if(j>i){
            dp[i][j].first=max(arr[i]+dp[i+1][j].second,arr[j]+dp[i][j-1].second);
            dp[i][j].second=min(dp[i+1][j].first,dp[i][j-1].first);
        }
    }
}
for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
        cout<<"("<<dp[i][j].first<<" "<<dp[i][j].second<<")"<<" ";
    }
    cout<<endl;
}
}

int main(){
    ll n=0;
    sl(n);
    ll arr[n+1];
    arr[0]=0;
    for(ll i=1;i<=n;++i)
        sl(arr[i]);
    filldp(arr,n);
    cout<<dp[1][n].first<<endl;
    return 0;
}
