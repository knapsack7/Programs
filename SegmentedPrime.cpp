#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a=0,b=0;
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

void showPrimes(){
    for(ll i:primesuptomillion){
        printf("%lld ",i);
    }
    printf("\n");
}

void primesInRange(ll a,ll b){
    ll len=b-a+1;
    for(int i=0;i<len;i++)
        arr.push_back(1);
    for(ll i=0;i<primesuptomillion.size()&&primesuptomillion[i]*primesuptomillion[i]<=b;i++){
        ll p=primesuptomillion[i];
        ll c=(a/p)*p;
        if(c<a)
            c=c+p;
        for(ll j=c;j<b+1;j=j+p){
            if(j==primesuptomillion[i])
                continue;
            if(j%primesuptomillion[i]==0){
                arr[j-a]=0;
            }
        }
    }
    for(ll i=0;i<len;i++){
            if(arr[i]==1){
                printf("%lld\n",i+a);
            }
    }
    printf("\n");
    arr.clear();
}

int main(){
ll t=0;
int N=1000000;
int arr[N];
for(int i=0;i<N;i++)//Initial All Prime;
    arr[i]=1;
sieve(N,arr);
//showPrimes();
scanf("%lld",&t);
while(t--){
    scanf("%lld%lld",&a,&b);
    primesInRange(a,b);
}
return 0;
}

