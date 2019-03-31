#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lim 1000000
#define sl(n) scanf("%lld",&n)
vector<bool> isprime(lim,1);
vector<ll> primes;
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
vector<ll> primesN;

void findPrime(ll n){
    ll i=0;
    while(n!=1){
        if(n%primes[i]==0){
            primesN.pb(primes[i]);
            n/=primes[i];
            while(n%primes[i]==0)
                n/=primes[i];
        }
        i++;
    }
}
ll phi(ll num){
    ll ans=num;
    for(ll i=0;i<primesN.size();i++){
        ans=(ans*(primesN[i]-1))/primesN[i];
    }
    primesN.clear();
    return ans;
}
int main(){
    sieve();
    ll t=0;
    sl(t);
    while(t--){
      ll n=0;
      sl(n);
      if(n==1)
          printf("1\n");
      else{
          findPrime(n);
          printf("%lld\n",phi(n));
      }
    }
    return 0;
}
