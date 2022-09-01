class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz, res;
    void func(const vi(vi(int))& v, ll in, vi(ll)& b, ll cnt) {
        if (in == sz) {
            for (ll it : b) {
                if (it != 0) {
                    return;
                }
            }
            res = max(res, cnt);
            return;
        }
        func(v, in + 1, b, cnt);
        b[v[in][0]]--, ++b[v[in][1]];
        func(v, in + 1, b, cnt + 1);
        ++b[v[in][0]], --b[v[in][1]];
    }
    int maximumRequests(int n, vector<vector<int>>& v) {
        sz = v.size(), res = 0;
        vi(ll)b(n);
        func(v, 0, b, 0);
        return res;
    }
};