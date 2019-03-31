#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)
ll dp[45];
void filldp(){
    dp[1]=2;
    dp[2]=3;
    for(ll i=3;i<45;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
}

int main(){
filldp();
ll t=0;
sl(t);
for(ll i=0;i<t;i++){
    ll n=0;
    sl(n);
    printf("#%lld : %lld\n",i+1,dp[n]);
}
return 0;
}
