class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    public:
    int totalHammingDistance(vi(ll)&v) {
        ll res = 0;
        for (ll i = 0;i < 32;++i) {
            ll odd = 0;
            for (ll& it : v) {
                if (it & 1) {
                    ++odd;
                }
                it >>= 1;
            }
            res += odd * (v.size() - odd);
        }
        return res;
    }
};