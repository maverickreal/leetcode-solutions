class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> singleNumber(vector<int>& v) {
        ll sz = v.size(), xo = 0;
        for (ll it : v)
            xo ^= it;
        ll mask = xo & (-xo);
        ll ot = 0, zt = 0;
        for (ll it : v) {
            if (it & mask) {
                ot ^= it;
            }
            else {
                zt ^= it;
            }
        }
        return { int(ot), int(zt) };
    }
};