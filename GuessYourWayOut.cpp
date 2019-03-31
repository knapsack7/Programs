#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	int t;
	cin>>t;
	while(t--){
        ll h,n;
	    cin>>h>>n;
	    n=pow(2,h)+n-1;// finding position ofexit node .. consider root node as index =1;
	    //cout<<n<<endl;
	    ll ans=0;
	    for(int i=h;i>=1;i--)// total no of hight need to travel
	    {
	       if(n%2==1 ) //means node is odd position
	        {
	            if((n/2)%2==1) //means parent is also odd position
	            {
	                ans+=pow(2,h-i+1);// need to cover left sub tree
	            }
	            else
	            {
	                ans+=1;// means L-R MOVE  so just include parrent
	            }
	            n/=2;//   shift exit node to upper level
	        }
	        else
	        {
	            if((n/2)%2==0)//  L-L move
	            {
	                ans+=pow(2,h-i+1);// cover right subtree
	            }
	            else
	            {
	                ans+=1;
	            }
	            n/=2;
	        }

	    }
	    cout<<ans<<endl;
	}
}
