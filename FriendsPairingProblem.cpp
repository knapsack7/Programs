#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)

ll dp[30]={0};

void filldp(){
    dp[1]=1;
    dp[2]=2;
    for(ll i=3;i<30;i++){
        dp[i]=(dp[i-1]+1)+dp[i-1]+dp[i-1];
    }
    for(ll a:dp)
        cout<<a<<endl;
    return 0;
}

int main(){
    ll t=0;
    sl(t);
    filldp();
    while(t--){
        ll n=0;
        sl(n);
        cout<<dp[n]<<endl;
    }
    return 0;
}
