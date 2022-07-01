// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define endl '\n'
const ll mod = 1e9;

bool check(const vi(bool)& v) {
    ll cnt = 0;
    for (const bool& b : v)
        if (b)
            ++cnt;
    return (cnt > 1);
}

int josephus(int n, int k) {
    vi(bool)v(n, true);
    ll cur = 0;
    while (check(v)) {
        ll nxt = cur, K = k - 1;
        while (K) {
            if (v[nxt])
                K--;
            nxt = (nxt + 1) % n;
        }
        while (!v[nxt])
            nxt = (nxt + 1) % n;
        v[nxt] = false;
        cur = nxt;
    }
    ll res = -1;
    for (ll i = 0; i < n && res == -1; ++i)
        if (v[i])
            res = i;
    return res+1;
}
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends