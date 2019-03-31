#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll n=0;
vector<ll> primesuptomillion;
vector<ll> arr;
void sieve(int N,int *p){
    p[2]=1;

    for(ll i=4;i<N;i+=2)
        p[i]=0;

    for(ll i=3;i*i<N;i+=2){
        if(p[i]){
            for(ll j=i*i;j<N;j+=2*i)
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
            if(value%p==0){
                factorsWithPower[p]++;
                value/=p;
                while(value%p==0){
                    value=value/p;
                }
            }
            j++;
            p=primesuptomillion[j];
        }
        if(value!=1){
            factorsWithPower[value]++;
        }
    }
    //cout<<factorsWithPower.size()<<endl;
    for(auto itr=factorsWithPower.begin();itr!=factorsWithPower.end();itr++){
	    cout<<itr->first<<"->"<<itr->second<<"\n";
    }
    factorsWithPower.clear();
}    


int main(){
ll t=0;
int N=1001;
int arr[N];
for(int i=0;i<N;i++)//Initial All Prime;
    arr[i]=1;
sieve(N,arr);
scanf("%lld",&t);
while(t--){
    int num=0;
    scanf("%lld",&num);
    for(int i=0;i<num;i++){
        scanf("%d",n);
    	factors(numbers);
    }
    int q=0;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
	int query=0;
	scanf("%d",&query);
	if(factorsWithPower.find(query)!=factorsWithPower.end())
		cout<<factorsWithPower[query]<<endl;
	else
		cout<<0<<endl;
    }
}
return 0;
}

