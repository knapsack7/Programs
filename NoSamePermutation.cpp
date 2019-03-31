#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
int cnt[100001]={0};
vector<int> inp;
int n=0;
int nextAvailableFromLeft(int *num1,int k){
    for(int i=0;i<k;++i){
        if(cnt[num1[i]]>0){
            return i;
        }
    }
    return -1;
}

int nextAvailableFromRight(int *num1,int pos,int k){
    for(int i=pos;i<k;++i){
        if(cnt[num1[i]]>0){
            return i;
        }
    }
    return -2;
}

void print(int *ans){
    for(int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    printf("\n");
}

void permute(int pos,int *num1,int *ans,int j,int k){
    if(pos==-2){
        return;
    }
    if(pos==-1){
        print(ans);
        return;
    }
    cnt[num1[pos]]--;
    ans[j]=num1[pos];
    int nextpos=nextAvailableFromLeft(num1,k);
    permute(nextpos,num1,ans,j+1,k);
    cnt[num1[pos]]++;
    nextpos=nextAvailableFromRight(num1,pos+1,k);
    permute(nextpos,num1,ans,j,k);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int t=0;
        scanf("%d",&t);
        inp.pb(t);
    }
	sort(inp.begin(),inp.begin()+n);
	for(int i=0;i<n;++i){
	    cnt[inp[i]]++;
	}
	int ans[n];
	int num1[100];
	num1[0]=inp[0];
	int j=0;
	for(int i=1;i<n;++i){
	    if(num1[j]!=inp[i]){
	        num1[++j]=inp[i];
	    }
	}
	permute(0,num1,ans,0,j+1);
	return 0;
}

