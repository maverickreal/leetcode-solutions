class Solution {
    typedef long long ll;
    typedef pair<ll, char> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n;
    vi(vi(vi(ll)))dp;
    ll func(const vi(vi(int))& v, ll a, ll b, ll x, ll y) {
        if (a == n || b == n || x == n || y == n || v[a][b] == -1 || v[x][y] == -1) {
            return -1;
        }
        if(a==n-1 && b==n-1){
            return v[a][b];
        }
        ll& ans = dp[a][b][x];
        if (ans == -2) {
            ans = v[a][b];
            if (x != a || y != b) {
                ans += v[x][y];
            }
            ll rec = max({ func(v,a, b + 1, x, y + 1), func(v, a, b + 1, x + 1, y), func(v, a + 1, b, x, y + 1), func(v, a + 1, b, x + 1, y) });
            if (rec > -1) {
                ans += rec;
            }
            else {
                ans = rec;
            }
        }
        return ans;
    }
    int cherryPickup(vector<vector<int>>& v) {
        n = v.size();
        dp.assign(n, vi(vi(ll))(n, vi(ll)(n, -2)));
        return max(0LL,func(v, 0, 0, 0, 0));
    }
};