class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
ll m,n;
vi(vi(ll))dp;
    ll func(const vi(vi(int))&v, ll i, ll j){
        if(i==m-1 && j==n-1){
            return min(0, v[i][j]);
        }
        if(i>=m || j>=n){
            return LLONG_MIN;
        }
        ll&ans=dp[i][j];
        if(ans==LLONG_MAX){
            ans=min(0LL, v[i][j]+max(func(v, i, j+1), func(v, i+1, j)));
        }
        return ans;
    }
    int calculateMinimumHP(vector<vector<int>>&v) {
        m=v.size(), n=v[0].size();
        dp.resize(m, vi(ll)(n, LLONG_MAX));
        return 1+abs(func(v, 0, 0));
    }
};