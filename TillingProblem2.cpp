#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)
#define pr(x) printf("%lld\n",x)

ll inf = 1e18;

int main(){
  ll t=1;
  sl(t);
  while(t--){
    ll n,m;
    sl(n);sl(m);
    vector<ll>dp(n+1,0);
    dp[0]=1ll;
    for(ll i=1;i<=n;i++){
      dp[i]=dp[i-1];
      dp[i]+=((i-m)>=0)?dp[i-m]:0;
      dp[i]%=MOD;
    }
    pr(dp[n]);
  }
}
