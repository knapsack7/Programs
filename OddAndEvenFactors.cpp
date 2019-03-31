#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 100001
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)
vector<bool> isprime(lim,1);
vector<ll> primes;
map<ll,ll> factorN;
ll n=-1;
void sieve(){
    for(ll i=3;i<=lim;i++){
        if(isprime[i]==1){
            for(ll j=i*i;j<=lim;j+=2*i){
                isprime[j]=0;
            }
        }
    }
    primes.pb(2);
    for(ll i=3;i<=lim;i+=2){
        if(isprime[i]==1){
            primes.pb(i);
        }
    }
}

void evaluate(){
    ll num=1,den=1;
    ll oddSum=0,isTwo=0;
    auto itr=factorN.begin();
    if(itr->first==2){
        ++itr;
        isTwo=1;
    }
    for(;itr!=factorN.end();++itr){
        num=num*(pow(itr->first,itr->second+1)-1);
        den=den*((itr->first)-1);
    }
    oddSum=num/den;
    num=0;
    ll evenSum=0;
    if(isTwo){
        itr=factorN.begin();
        for(ll i=1;i<=itr->second;++i){
            num=num+pow(2,i);
        }
    }
    evenSum=num*oddSum;
    ll ans=evenSum-oddSum;
    cout<<ans<<endl;
    factorN.clear();
}

void factorisation(){
    ll j=0;
    ll p=primes[j];
    while(p*p<=n){
        if(n%p==0){
            factorN[p]++;
            n/=p;
            while(n%p==0){
                n/=p;
                factorN[p]++;
            }
        }
        j++;
        p=primes[j];
    }
    if(n!=1)
        factorN[n]++;
    evaluate();
}

int main(){
    sieve();
    ll t=0;
    sl(t);
    while(t--){
        sl(n);
        factorisation();
    }
    return 0;
}
