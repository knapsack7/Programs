//See Tushars Dp Optimal Game Strategy video
//Same as Optimal Game Strategy only issue is tha arr can not exceed 10^7 hence we use map here
//Given Constraint are dp[10^4][10^4]
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
map<pair<int,int>,pair<int,int>> dp;

void filldp(ll *arr,ll n){
pair<ll,ll> t;
for(ll i=1;i<=n;++i){
    t.first=arr[i];
    t.second=0;
    dp[make_pair(i,i)]=t;
}
for(ll k=1;k<n;++k){
    for(ll i=1,j=i+k;j<=n;++i,++j){
        t.first=max(arr[i]+dp[make_pair(i+1,j)].second,arr[j]+dp[make_pair(i,j-1)].second);
        t.second=min(dp[make_pair(i+1,j)].first,dp[make_pair(i,j-1)].first);
        dp[make_pair(i,j)]=t;
        //dp[i][j].first=max(arr[i]+dp[i+1][j].second,arr[j]+dp[i][j-1].second);
        //dp[i][j].second=min(dp[i+1][j].first,dp[i][j-1].first);
    }
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
    cout<<dp[make_pair(1,n)].first<<endl;
    return 0;
}
