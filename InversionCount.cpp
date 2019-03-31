#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)

ll inversion_cnt=0;

void crossCount(ll *a,ll m,ll n,ll p,ll q){
    //Counting Cross Count
    ll i=m;ll j=p;
    while(i<=n && j<=q){
        if(a[i]>a[j]){
            j++;
            inversion_cnt+=(n-i)+1;
        }
        if(a[i]<a[j]){
            i++;
        }
    }
    ll tempArr[100001];
    ll t=0;
    i=m,j=p;

    //Merging the array
    while(i<=n && j<=q){
        if(a[i]<a[j]){
            tempArr[t++]=a[i];
            i++;
        }
        else if(a[i]>a[j]){
            tempArr[t++]=a[j];
            j++;
        }
    }
    while(i<=n){
        tempArr[t++]=a[i++];
    }
    while(j<=q){
        tempArr[t++]=a[j++];
    }
    for(ll k=m,l=0;l<t;k++,l++){//making Changes in Original Array
        a[k]=tempArr[l];
    }
}

void inversionCount(ll *a,ll s,ll e){
    if(s>=e){
        return;
    }
    ll mid=(s+e)/2;
    inversionCount(a,s,mid);
    inversionCount(a,mid+1,e);
    crossCount(a,s,mid,mid+1,e);
}

int main(){
    ll test=0;
    sl(test);
    while(test--){
        ll n=0;
        sl(n);
        ll input[n];
        inversion_cnt=0;
        for(ll i=0;i<n;++i)
            sl(input[i]);
        inversionCount(input,0,n-1);
        cout<<inversion_cnt<<endl;
    }
    return 0;
}
