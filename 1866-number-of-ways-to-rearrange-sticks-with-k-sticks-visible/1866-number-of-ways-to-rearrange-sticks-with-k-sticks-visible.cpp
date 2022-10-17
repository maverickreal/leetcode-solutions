class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll func(ll n, ll k){
        if(n<k || k<0 || n<0){
            return 0;
        }
        if(n==1){
            return (k==1);
        }
        ll&ans=dp[n][k];
        if(ans==-1){
            ans=(func(n-1, k-1)+(n-1)*func(n-1, k))%mod;
        }
        return ans;
    }
    int rearrangeSticks(int n, int k) {
        dp.assign(n+1, vi(ll)(k+1, -1));
        return func(n, k);   
    }
};