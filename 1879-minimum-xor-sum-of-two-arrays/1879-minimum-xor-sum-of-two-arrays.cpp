class Solution {
    typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(ll))dp;
    ll func(const vi(int)&va, const vi(int)&vb, ll in, ll bm){
        if(in==n){
            return 0;
        }
        ll&ans=dp[in][bm];
        if(ans==-1){
            ans=LLONG_MAX;
            for(ll i=0;i<n;++i){
                if(!((bm>>i)&1)){
                    ans=min(ans, (vb[i]^va[in])+func(va, vb, in+1, bm|(1<<i)));
                }
            }
        }
        return ans;
    }
    int minimumXORSum(vector<int>&va, vector<int>&vb) {
        n=vb.size();
        dp.assign(n, vi(ll)(1<<n, -1));
        return func(va, vb, 0, 0);
    }
};