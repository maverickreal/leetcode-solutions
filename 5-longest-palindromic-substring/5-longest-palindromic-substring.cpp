class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string longestPalindrome(string& s) {
        ll sz = 2 * s.length() + 1;
        string str(sz, '#');
        for (ll i = 1;i < sz;i += 2) {
            str[i] = s[i / 2];
        }
        vi(ll)v(sz);
        ll r = 0, c = 0, resc = 0, resr = 0;
        for (ll i = 0;i < sz;++i) {
            ll m = 2 * c - i;
            if (i < r) {
                v[i] = min(v[m], r - i);
            }
            ll x = i - v[i], y = i + v[i];
            while (x && y < sz - 1 && str[x - 1] == str[y + 1]) {
                --x;
                ++y;
                ++v[i];
            }
            if (v[i] > v[resc]) {
                resc = i;
                resr = v[i];
            }
            if (v[i] > v[c]) {
                c = i;
                r = i + v[i];
            }
        }
        string res;
        for (ll i = resc - resr;i <= resc + resr;++i) {
            if (str[i] != '#') {
                res.pb(str[i]);
            }
        }
        return res;
    }
};