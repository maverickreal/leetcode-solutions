class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll) finalPrices(const vi(ll)&v) {
        ll sz = v.size();
        vi(ll)st, ans(sz, -1);
        for (ll i = sz - 1;i > -1;--i) {
            while (!st.empty() && v[st.back()] > v[i]) {
                st.pop_back();
            }
            if (!st.empty()) {
                ans[i] = st.back();
            }
            st.pb(i);
        }
        for (ll i = 0;i < sz;++i) {
            ans[i] = v[i] - (ans[i] == -1 ? 0 : v[ans[i]]);
        }
        return ans;
    }
};