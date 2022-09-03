class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int minKBitFlips(vector<int>& v, int k) {
        map<ll, ll>mp;
        ll res = 0, sz = v.size(), ts = 1;
        for (ll i = 0;i <= sz - k;++i) {
            bool flip = 0;
            auto it = mp.lower_bound(i);
            if (it != mp.end()) {
                flip = (mp.rbegin()->second - it->second + 1) & 1;
            }
            if (flip) {
                v[i] = !v[i];
            }
            if (v[i] == 0) {
                ++res;
                mp[i + k - 1] = ts++;
            }
        }
        for (ll i = sz - k + 1;i < sz;++i) {
            bool flip = 0;
            auto it = mp.lower_bound(i);
            if (it != mp.end()) {
                flip = (mp.rbegin()->second - it->second + 1) & 1;
            }
            if (flip) {
                v[i] = !v[i];
            }
            if (v[i] == 0) {
                return -1;
            }
        }
        return res;
    }
};