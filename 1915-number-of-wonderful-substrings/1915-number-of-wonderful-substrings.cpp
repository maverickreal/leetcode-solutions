class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    long long wonderfulSubstrings(string& s) {
        vi(ll)ump(1024);
        ++ump[0];
        ll ans = 0, bm = 0;
        for (char ch : s) {
            bm ^= 1 << (ch - 'a');
            ans += ump[bm];
            for (ll i = 0;i < 10;++i) {
                ans += ump[bm ^ (1 << i)];
            }
            ump[bm]++;
        }
        return ans;
    }
};