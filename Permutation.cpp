#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)

int len=0;
void permute(char *in,char *out,int i){
    if(in[i]=='\0'){
        out[i]='\0';
        cout<<out<<endl;
        return;
    }

    for(int k=i;k<len;++k){
        swap(out[i],out[k]);
        permute(in,out,i+1);
        swap(out[i],out[k]);
    }

}

int main(){
char in[100];
char out[100];

cin>>in;

strcpy(out,in);

len=strlen(in);

permute(in,out,0);


}
