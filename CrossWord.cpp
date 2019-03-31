#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<string> dict;
char crossword[5][5];
int m=1;
int markIfVisited[5][5]={0};
bool isInCrossWord(int i,int j,string word,int k,int len,int M){
        if(k==len){
            return true;
        }

        if((i<M&&i>=0 && j<M&&j>=0) && crossword[i][j]==word[k] && markIfVisited[i][j]==0){
            markIfVisited[i][j]=m++;
            return (isInCrossWord(i-1,j-1,word,k+1,len,M)||
                    isInCrossWord(i-1,j,word,k+1,len,M)||
                    isInCrossWord(i-1,j+1,word,k+1,len,M)||
                    isInCrossWord(i,j-1,word,k+1,len,M)||
                    isInCrossWord(i,j+1,word,k+1,len,M)||
                    isInCrossWord(i+1,j-1,word,k+1,len,M)||
                    isInCrossWord(i+1,j,word,k+1,len,M)||
                    isInCrossWord(i+1,j+1,word,k+1,len,M)
                    );
        }
        return false;
}

int main(){
    int N=0,M=0;
    cin>>N;
    for(int i=0;i<N;i++){
        string t;
        cin>>t;
        dict.pb(t);
    }
    cin>>M;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cin>>crossword[i][j];
        }
    }
    set<string> ansDict;
    for(int i=0;i<N;i++){
        int found=0;
        for(int j=0;j<M;j++){
            for(int k=0;k<M;k++){
                m=1;
                memset(markIfVisited,0,sizeof(markIfVisited));
                if(isInCrossWord(j,k,dict[i],0,dict[i].length(),M)){
                    ansDict.insert(dict[i]);
                    break;
                }
            }
            if(found)
                break;
        }
    }
    for(auto itr=ansDict.begin();itr!=ansDict.end();++itr){
        cout<<*itr<<" ";
    }
    return 0;
}
