// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    typedef long long ll;
public:
    int countFriendsPairings(int n) 
    { 
    const ll mod = 1e9+7;
    ll preAlone=1, preDuo=0, pre=1;
    while(--n){
        
        ll tmp=preAlone;
        preAlone=(preDuo+preAlone)%mod;
        preDuo=(tmp*pre)%mod;
        ++pre;
    }
    return (preAlone+preDuo)%mod;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends