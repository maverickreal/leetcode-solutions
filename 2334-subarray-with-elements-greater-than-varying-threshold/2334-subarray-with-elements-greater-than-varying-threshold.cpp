class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int validSubarraySize(vector<int>& v, int t) {
        ll sz = v.size();
        vi(ll)pre(sz, -1), nxt(sz, sz), st;
        for (ll i = 0;i < sz;++i) {
            while (!st.empty() && v[st.back()] > v[i]) {
                nxt[st.back()] = i;
                st.pop_back();
            }
            st.pb(i);
        }
        st.clear();
        for (ll i = sz - 1;i > -1;--i) {
            while (!st.empty() && v[st.back()] > v[i]) {
                pre[st.back()] = i;
                st.pop_back();
            }
            st.pb(i);
        }
        st.clear();
        ll res = -1;
        for (ll i = 0;i < sz;++i) {
            ll range = nxt[i] - pre[i] - 1;
            if (range > 0 && v[i] > (t / range)) {
                res = range;
                //cout<<i<<' '<<pre[i]<<' '<<nxt[i]<<nl;
                break;
            }
        }
        return res;
    }
};