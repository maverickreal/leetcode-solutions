class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    ll func(const vi(unordered_set<ll>)& ump, ll i, ll j) {
        ll ans = 0;
        for (auto it = ump[i].begin();it != ump[i].end();++it) {
            if (ump[j].find(*it) == ump[j].end()) {
                continue;
            }
            for (auto ti = next(it);ti != ump[i].end();++ti) {
                if (ump[j].find(*ti) != ump[j].end()) {
                    ++ans;
                }
            }
        }
        return ans;
    }
    int countCornerRectangles(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        ll ans = 0;
        vi(unordered_set<ll>)ump(m);
        for (ll i = 0;i < m;++i) {
            for (ll j = 0;j < n;++j) {
                if (v[i][j]) {
                    ump[i].insert(j);
                }
            }
        }
        for (ll i = 0;i < m;++i) {
            if (ump[i].size() < 2) {
                continue;
            }
            for (ll j = i + 1;j < m;++j) {
                if (ump[j].size() > 1) {
                    ans += func(ump, i, j);
                }
            }
        }
        return ans;
    }
};