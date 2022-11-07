class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
ll m,n;
vi(vi(ll))dp, dirs={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
ll func(const vi(vi(int))&v, ll i, ll j){
    ll&ans=dp[i][j];
    if(ans==-1){
        ans=1;
        for(const vi(ll)&dir:dirs){
            ll x=i+dir[0], y=j+dir[1];
            if(x>-1 && x<m && y>-1 && y<n && v[x][y]>v[i][j]){
                ans=(ans+func(v, x, y))%mod;
            }
        }
    }
    return ans;
}
int countPaths(vector<vector<int>>&v) {
    m=v.size(), n=v[0].size();
    dp.assign(m, vi(ll)(n, -1));
    ll ans=0;
    for(ll i=0;i<m;++i){
        for(ll j=0;j<n;++j){
            ans=(ans+func(v, i, j))%mod;
        }
    }
    return ans;
}
};