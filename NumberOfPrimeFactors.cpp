#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll n=0;
vector<ll> primesuptomillion;
vector<ll> arr;
void sieve(int N,int *p){
    p[2]=1;

    for(ll i=4;i<N;i+=2)//Mark all Even Non Prime
        p[i]=0;

    for(ll i=3;i*i<N;i+=2){//Consider only Odd Number which can be prime that why i+=2
        if(p[i]){
            for(ll j=i*i;j<N;j+=2*i)//j+=2*i since j is always odd number hence to consider odd number we increament j by 2*i
                p[j]=0;
        }
    }
    for(ll i=2;i<N;i++){
        if(p[i]==1){
            primesuptomillion.push_back(i);
        }
    }
}

map<int,int> factorsWithPower;
void factors(){
    int j=0;
	ll p=primesuptomillion[j];
    while(p*p<=n){
        if(n%p==0){
            factorsWithPower[p]++;
            n/=p;
            while(n%p==0){
                factorsWithPower[p]++;
                n=n/p;
            }
        }
        j++;
        p=primesuptomillion[j];
    }
    if(n!=1){
        factorsWithPower[n]++;
    }
    //cout<<factorsWithPower.size()<<endl;
	ll ans=1;
    for(auto itr=factorsWithPower.begin();itr!=factorsWithPower.end();itr++){
	    //cout<<itr->first<<"->"<<itr->second<<"\n";
        ans=ans*(itr->second+1);
    }
    cout<<ans<<endl;
    factorsWithPower.clear();
}    


int main(){
ll t=0;
int N=1000000;
int arr[N];
for(int i=0;i<N;i++)//Initial All Prime;
    arr[i]=1;
sieve(N,arr);
scanf("%lld",&t);
while(t--){
    scanf("%lld",&n);
    factors();
}
return 0;
}

