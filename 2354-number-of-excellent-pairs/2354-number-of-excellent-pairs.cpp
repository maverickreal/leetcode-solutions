class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    long long countExcellentPairs(vector<int>& v, int k) {
        ll ans = 0;
        vi(ll)ump(32);
        for (ll it : unordered_set<ll>(v.begin(), v.end())) {
            ++ump[__builtin_popcount(it)];
        }
        for (ll i = 0;i < 32;++i) {
            for (ll j = 0;j < 32;++j) {
                if (i + j >= k) {
                    ans += ump[i] * ump[j];
                }
            }
        }
        return ans;
    }
};