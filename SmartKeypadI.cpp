#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define pb push_back
#define sl(n) scanf("%lld",&n)

char keypad[][10]={" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void phoneKeypadString(char *in,char *out,int i,int j){

    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<",";
        return;
    }

    int digit=in[i]-'0';



    for(int k=0;keypad[digit][k]!='\0';++k){
        out[j]=keypad[digit][k];
        phoneKeypadString(in,out,i+1,j+1);
    }
}

int main(){
    char in[100];
    char out[100];

    cin>>in;

    phoneKeypadString(in,out,0,0);

    return 0;
}
