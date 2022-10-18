class Solution {
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll func(const vi(int)&v, ll i, ll j){
        if(j==i+1){
            return 0;
        }
        ll&ans=dp[i][j];
        if(ans==-1){
            ans=LLONG_MAX;
            for(ll k=i+1;k<j;++k){
                ans=min(ans, func(v, i, k)+func(v, k, j));
            }
            ans+=v[j]-v[i];
        }
        return ans;
    }
    int minCost(int n, vector<int>&v) {
        v.pb(0), v.pb(n);
        sort(begin(v), end(v));
        dp.assign(v.size(), vi(ll)(v.size(), -1));
        return func(v, 0, v.size()-1);
    }
};