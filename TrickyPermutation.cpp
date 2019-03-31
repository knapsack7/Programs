#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)
ll cnt[26]={0};

int nextAvailableFromLeft(char *str1){// returns ascii value for character otherwise 0
    for(ll i=0;str1[i]!='\0';++i){
        if(cnt[str1[i]-65]>0){
            return i;
        }
    }
    return -1;
}

int nextAvailableFromRight(char *str1,int pos){//this returns the index of next available character otherwise -1
    for(ll i=pos;str1[i]!='\0';++i){
        if(cnt[str1[i]-65]>0){
            return i;
        }
    }
    return -2;
}

void permute(int pos,char *str1,char *ans,ll j){
    if(pos==-2){
        return;
    }
    if(pos==-1){
        ans[j]='\0';
        cout<<ans<<endl;
        return;
    }
    cnt[str1[pos]-65]--;
    ans[j]=str1[pos];
    int nextpos=nextAvailableFromLeft(str1);
    //cout<<nextpos<<endl;
    permute(nextpos,str1,ans,j+1);
    cnt[str1[pos]-65]++;
    nextpos=nextAvailableFromRight(str1,pos+1);
    //cout<<nextpos<<endl;
    permute(nextpos,str1,ans,j);
}


int main() {
	string str;
	cin>>str;
	sort(str.begin(),str.end());
	//cout<<str<<endl;
	for(ll i=0;i<str.length();++i){
	    cnt[str[i]-65]++;
	}
	char ans[100];
	char str1[100];
	str1[0]=str[0];
	int j=0;
	for(int i=1;i<str.length();++i){//Remove duplicates
	    if(str1[j]!=str[i]){
	        str1[++j]=str[i];
	    }
	}
    str1[++j]='\0';
	//cout<<str1<<endl;
	//for(int i=0;i<26;i++)
	    //cout<<(char)(65+i)<<" "<<cnt[i]<<endl;
    permute(0,str1,ans,0);
	return 0;
}
