class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    unordered_map<ll,unordered_map<ll,ll>>dp;
    ll func(ll in, const int&n, ll rem){
        if(in<0 || in>=n || rem<in ){
            return 0;
        }
        if(rem==in){
            return 1;
        }
        if(dp[in].find(rem)==dp[in].end()){
            dp[in][rem]=-1;
        }
        ll&ans=dp[in][rem];
        if(ans==-1){
            ans=(func(in-1, n, rem-1)+func(in, n, rem-1)+func(in+1, n, rem-1))%mod;
        }
        return ans;
    }
    int numWays(int k, int n) {
        //dp.assign(n, vi(ll)(k+1, -1));
        return func(0, n, k);
    }
};