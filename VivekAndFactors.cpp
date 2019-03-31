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
ll sumOfFactor[100001];
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

void evaluate(ll i){
    ll num=1,den=1;
    for(auto itr=factorN.begin();itr!=factorN.end();++itr){
        num=num*(pow(itr->first,itr->second+1)-1);
        den=den*((itr->first)-1);
    }
    ll ans=num/den;
    if(ans<=100000)// sum of factors may go beyond 100000
        sumOfFactor[(int)ans]=i;
    factorN.clear();
}

void factorisation(){
    for(ll i=2;i<100001;i++){
        ll num=i,j=0;
        ll p=primes[j];
        while(p*p<=num){
            if(num%p==0){
                factorN[p]++;
                num/=p;
                while(num%p==0){
                    num/=p;
                    factorN[p]++;
                }
            }
            j++;
            p=primes[j];
        }
        if(num!=1)
            factorN[num]++;
        evaluate(i);
    }
}

int main(){
    sieve();
    memset(sumOfFactor,-1,sizeof(sumOfFactor));
    sumOfFactor[0]=0;
    sumOfFactor[1]=1;
    sumOfFactor[2]=-1;
    factorisation();
    while(n!=0){
        sl(n);
        if(n!=0)
            cout<<sumOfFactor[n]<<endl;
    }
    for(ll i=0;i<100001;i++)
    cout<<i<<" "<<sumOfFactor[i]<<endl;
    return 0;
}
