class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll m,n;
    vi(vi(ll))dp;
    ll func(const vi(vi(int))&v, ll i, ll j, ll pre){
        if(i<0 || j<0 || i>=m || j>=n || v[i][j]<=pre){
            return 0;
        }
        ll&ans=dp[i][j];
        if(ans==-1){
            ans=1+max({func(v, i+1, j, v[i][j]), func(v, i, j+1, v[i][j]), func(v, i-1, j, v[i][j]), func(v, i, j-1, v[i][j])});
        }
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>&v) {
        m=v.size(), n=v[0].size();
        dp.assign(m, vi(ll)(n, -1));
        ll ans=0;
        for(ll i=0;i<m;++i){
            for(ll j=0;j<n;++j){
                if(dp[i][j]==-1){
                    func(v, i, j, -1);
                }
                ans=max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};