class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(vi(ll)))dp;
    ll n;
    ll func(const vi(int)&v, ll in, bool bought, ll rem){
        if(in>=n || rem<1){
            return 0;
        }
        ll&ans=dp[in][rem][bought];
        if(ans==-1){
            if(bought){
                ans=max(func(v, in+1, bought, rem), v[in]+func(v, in+1, 0, rem-1));
            }
            else{
                ans=max(func(v, in+1, 0, rem), -v[in]+func(v, in+1, 1, rem));
            }
        }
        return ans;
    }
    int maxProfit(int k, vector<int>&v) {
        n=v.size();
        dp.assign(n, vi(vi(ll))(k+1, vi(ll)(2, -1)));
        return func(v, 0, 0, k);
    }
};