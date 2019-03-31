#include<bits/stdc++.h>
using namespace std;

char output[100];

void printSubsequence(){
    for(int i=0;output[i]!='\0';++i)
        printf("%c",output[i]);
    cout<<endl;
}
int len=0;
void permute(string str,int j,int pos_i){

    if(pos_i>len){
        return;
    }

    if(str[pos_i]=='\0'){
            output[pos_i]='\0';
            printSubsequence();
            return;
    }

    output[j]=str[pos_i];
    permute(str,j+1,pos_i+1);
    output[j]=32;// 32 is ASCII value for space character
    permute(str,j,pos_i+1);
}

int main(){
string str;
cin>>str;
len=str.size();
//for(int i=0;str[i]!='\0';i++)
    //cout<<str[i]<<" ";
permute(str,0,0);
return 0;
}
