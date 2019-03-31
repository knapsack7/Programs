#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%d",&n)
int n=0,target=0;
vector<int> inp;
int isprinted[16][16][1501]={0};
void print(int *ans,int k){
    for(int i=0;i<k;++i)
        cout<<ans[i]<<" ";
    cout<<endl;
}

void sumIt(int j,int pos,int *ans,int target){
    if(target<0){
        return;
    }
    if(isprinted[j][pos][target]==1)
        return;
    if(target==0){
        //cout<<pos<<endl;
        print(ans,j);
        isprinted[j][pos][target]=1;
        return;
    }
    if(pos<n)
        ans[j]=inp[pos];
    else
        return;
    sumIt(j+1,pos+1,ans,target-inp[pos]);
    sumIt(j,pos+1,ans,target);
}

int main(){
    sl(n);
    int t=0;
    for(int i=0;i<n;++i){
        sl(t);
        inp.pb(t);
    }
    sort(inp.begin(),inp.end());
    int ans[n];
    sl(target);
    //for(int i:inp)
        //cout<<i<<endl;
    sumIt(0,0,ans,target);
    return 0;
}
