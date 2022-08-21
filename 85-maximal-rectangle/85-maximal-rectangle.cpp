class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll func(const vi(ll)& v) {
        ll sz = v.size();
        vi(ll)pre(sz, -1), post(sz, sz), st;
        for (ll i = 0;i < sz;++i) {
            while (!st.empty() && v[st.back()] > v[i]) {
                post[st.back()] = i;
                st.pop_back();
            }
            st.pb(i);
        }
        while (!st.empty()) {
            st.pop_back();
        }
        for (ll i = sz - 1;i > -1;--i) {
            while (!st.empty() && v[st.back()] > v[i]) {
                pre[st.back()] = i;
                st.pop_back();
            }
            st.pb(i);
        }
        ll ans = 0;
        for (ll i = 0;i < sz;++i) {
            ans = max(ans, v[i] * (post[i] - pre[i] - 1));
        }
        return ans;
    }
    ll maximalRectangle(const vi(vi(char))&v) {
        ll m = v.size(), n = v[0].size();
        vi(ll)h(n, 0);
        ll ans = 0;
        for (ll i = 0;i < m;++i) {
            for (ll j = 0;j < n;++j) {
                if (v[i][j] == '1') {
                    h[j]++;
                }
                else {
                    h[j] = 0;
                }
            }
            ans = max(ans, func(h));
        }
        return ans;
    }
};