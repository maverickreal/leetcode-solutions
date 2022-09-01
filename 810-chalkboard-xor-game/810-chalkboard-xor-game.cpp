class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool xorGame(vector<int>& v) {
        ll xo = 0;
        for (ll it : v) {
            xo ^= it;
        }
        return !(xo && (v.size() & 1));
    }
};