class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(ll))ump, dp;
    ll func(ll hat, ll bm){
        if(__builtin_popcount(bm)==n){
            return 1;
        }
        if(hat==41){
            return 0;
        }
        ll&ans=dp[hat][bm];
        if(ans==-1){
            ans=func(hat+1, bm);
            for(ll person:ump[hat]){
                if( !((bm>>person)&1) ){
                    ans=(ans+func(hat+1, bm|(1<<person)))%mod;
                }
            }
        }
        return ans;
    }
    int numberWays(vector<vector<int>>&v) {
        n=v.size();
        ump.assign(41, {});
        dp.assign(41, vi(ll)(1<<n, -1));
        for(ll i=0;i<n;++i){
            for(ll j:v[i]){
                ump[j].pb(i);
            }
        }
        return func(1, 0);
    }
};