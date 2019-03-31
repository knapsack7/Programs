#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)
ll n=0;

ll calculateAns(ll a,ll n,ll p){
	if(n==1){
		return a;
	}
	if(n&1){
		return ((a%p)*(calculateAns(a,n-1,p))%p)%p;
	}
	ll ans=calculateAns(a,n/2,p)%p;
	return ((ans%p)*(ans%p))%p;
}

int main(){
	ll A,N,P,t=0;
	sl(t);
	while(t--){
		cin>>A>>N>>P;
		while(N>=1){
			A=calculateAns(A,N,P)%P;
			N--;
		}
		cout<<A<<endl;
	}
	return 0;
}
