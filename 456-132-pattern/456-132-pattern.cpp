class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool find132pattern(vector<int>& v) {
        ll sz = v.size();
        vi(ll)mn(sz);
        mn[0] = v[0];
        for (ll i = 1;i < sz;++i) {
            mn[i] = min(mn[i - 1], ll(v[i]));
        }
        list<ll>st = { v.back() };
        for (ll i = sz - 2;i > 0;--i) {
            while (!st.empty() && st.back() <= mn[i - 1]) {
                st.pop_back();
            }
            if (!st.empty() && st.back() < v[i]) {
                return true;
            }
            st.pb(v[i]);
        }
        return false;
    }
};