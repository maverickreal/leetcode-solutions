class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int getXORSum(const vi(int)& a, const vi(int)& b) {
        ll xo = 0;
        for (ll it : b) {
            xo ^= it;
        }
        ll res = 0;
        for (ll it : a) {
            res ^= it & xo;
        }
        return res;
    }
};