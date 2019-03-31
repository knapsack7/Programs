#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ans=0;

ll sum(ll *inc,ll j){
	ll s=inc[0];
	//cout<<"f"<<endl;
	for(ll i=1;i<=j;++i){
		s+=inc[i];
	}
	return s;
}

void solve(ll i,ll j,ll n,ll *arr,ll *inc){
	if(i==n){
		ll a=sum(inc,j);
		//cout<<a<<endl;
		if(a==0)
			ans=1;
		return;
	}
	inc[j]=arr[i];
	solve(i+1,j+1,n,arr,inc);
	solve(i+1,j,n,arr,inc);
}

int main(){
	ll t=0;
	cin>>t;
	for(ll i=1;i<=t;++i){
		ans=0;
		ll n=0;
		cin>>n;
		ll arr[n];
		ll inc[100];
		for(ll i=0;i<n;++i){
			cin>>arr[i];
		}
		//cout<<arr[0]<<endl;
		solve(0,0,n,arr,inc);
		if(ans==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
