#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)
ll n=0;
char pattern[100];
void solve(int pos,int openCnt,int closeCnt,int k){
    if(k==(2*n)){
        //cout<<"h"<<endl;
        for(int i=0;i<pos;++i)
            printf("%c",pattern[i]);
        printf("\n");
        return;
    }
    if(openCnt>closeCnt){
        pattern[pos]=')';
        solve(pos+1,openCnt,closeCnt+1,k+1);
    }
    if(openCnt<n){
        pattern[pos]='(';
        solve(pos+1,openCnt+1,closeCnt,k+1);
    }
}


int main(){
    sl(n);
    solve(0,0,0,0);
    return 0;
}
