class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        ll sz = v.size();
        vi(ll)st;
        for (ll i = sz - 2;i > -1;--i) {
            while (!st.empty() && v[i]>=st.back()) {
                st.pop_back();
            }
            st.push_back(v[i]);
        }
        for (ll i = sz - 1;i > -1;--i) {
            while (!st.empty() && v[i]>=st.back()) {
                st.pop_back();
            }
            ll it=v[i];
            v[i] = st.empty() ? -1 : st.back();
            st.push_back(it);
        }
        return v;
    }
};