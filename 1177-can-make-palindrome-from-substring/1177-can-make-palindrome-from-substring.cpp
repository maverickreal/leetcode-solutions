class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        ll sz = s.length(), szq = q.size();
        vi(bool)ans(szq, false);
        vi(ll)bm(sz, 0);
        bm[0] = 1 << (s[0] - 'a');
        for (ll i = 1;i < sz;++i) {
            bm[i] = bm[i - 1] ^ (1 << (s[i] - 'a'));
        }
        for (ll i = 0;i < szq;++i) {
            ll o = 0, mask = bm[q[i][1]];
            if (q[i][0] > 0) {
                mask ^= bm[q[i][0] - 1];
            }
            while (mask) {
                o += mask & 1;
                mask >>= 1;
            }
            if (q[i][2] >= o / 2) {
                ans[i] = true;
            }
        }
        return ans;
    }
};