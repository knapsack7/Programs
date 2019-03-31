#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)
vector<ll> input;
ll n=0,MAX=0;
ll ans[1000000];
ll cnt[1000000];
void countMultiple(){
    MAX=input[0];
    for(ll i=0;i<n;i++){
        if(input[i]>MAX)
            MAX=input[i];
    }
    for(ll i=0;i<=MAX;i++){
        ans[i]=cnt[i]=0;
    }

    cout<<MAX<<endl;
    for(ll i=0;i<n;i++){
        cnt[input[i]]++;
    }
    for(ll i=1;i<=MAX;i++){
        for(ll j=i;j<=MAX;j=j+i){
            ans[j]=ans[j]+cnt[j];
        }
    }
}

int main(){
sl(n);
ll temp=0;
for(int i=0;i<n;i++){
    sl(temp);
    input.pb(temp);
}
ll q=0;
sl(q);
for(ll i=0;i<q;i++){
    sl(temp);
    if(temp<=MAX)
        printf("%lld\n",ans[temp]);
    else
        printf("0\n");
}
return 0;
}
