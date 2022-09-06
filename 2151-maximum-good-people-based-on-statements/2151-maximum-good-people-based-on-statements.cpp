class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int maximumGood(vector<vector<int>>& v) {
        ll n = v.size(), ans = 0;
        for (ll bm = 0;bm < (1 << n);++bm) {
            bool take = true;
            for (ll i = 0;i < n;++i) {
                if (!((bm >> i) & 1)) {
                    continue;
                }
                for (ll j = 0;j < n;++j) {
                    if (v[i][j] != 2 && v[i][j] != ((bm >> j) & 1)) {
                        take = false;
                        break;
                    }
                    //cout<<i<<' '<<j<<' '<<v[i][j]<<' '<<bm<<' '<<((bm >> j) & 1)<<nl;
                }
                if (!take) {
                    break;
                }
            }
            if (take) {
                ans = max(ans, ll(__builtin_popcount(bm)));
            }
            //cout << bm << ' ' << ans << nl;
        }
        return ans;
    }
};