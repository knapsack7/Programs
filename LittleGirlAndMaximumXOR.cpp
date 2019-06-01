#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//www.quora.com/What-is-the-intuition-behind-this-solution
int main(){
   ll l,r;
   cin>>l>>r;
   ll p=l^r;
   ll x=1;
   while(x<=p){
    x=x<<1;
   }
   cout<<x-1<<endl;
   return 0;
}
