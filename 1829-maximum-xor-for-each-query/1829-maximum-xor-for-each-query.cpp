class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> getMaximumXor(vector<int>& v, int bit) {
        ll sz = v.size();
        for (ll i = 1;i < sz;++i)
            v[i] ^= v[i - 1];
        bit = (1 << bit) - 1;
        vi(ll)ans(sz);
        for (ll i = 0;i < v.size();++i)
            ans[i] = bit ^ v[sz - 1 - i];
        return ans;
    }
};