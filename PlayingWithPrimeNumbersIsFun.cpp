#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sl(n) scanf("%lld",&n)
ll n=0,ans=1,MOD=1000000007;
ll powersN[1000006];
ll product=1;
ll powersP[1000006]={0};
int main(){
	sl(n);
	for(ll i=0;i<n;++i){
		sl(powersN[i]);
		product=((product%MOD)*(powersN[i]+1))%MOD;
	}
	for(ll i=0;i<n;++i){
		    ll p=((powersN[i])%MOD*(powersN[i]+1)%MOD)/2;
		    ll mf=product/(powersN[i]+1);
		    powersP[i]=((p%MOD)*(mf%MOD))%MOD;
	}
	for(ll i=0;i<n;++i){
		    ans=((ans%MOD)*(powersP[i]+1)%MOD)%MOD;
	}
    printf("%lld\n",ans);	
	return 0;
}