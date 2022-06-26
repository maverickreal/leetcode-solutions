class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
public:
    int maximumsSplicedArray(vector<int>& va, vector<int>& vb) {
        const ll n = va.size();
        ll suma = accumulate(va.begin(), va.end(), 0ll),
            sumb = accumulate(vb.begin(), vb.end(), 0ll);
        ll ans = max(suma, sumb);
        ll f = 0, s = 0, mxa = 0, mxb = 0;
        for (ll i = 0;i < n;++i) {
            f += va[i] - vb[i];
            s += vb[i] - va[i];
            mxa = max(mxa, f);
            mxb = max(mxb, s);
            if (f < 0) f = 0;
            if (s < 0) s = 0;
        }
        ans = max(ans, suma + mxb);
        ans = max(ans, sumb + mxa);
        ans = max(ans, suma - mxa);
        ans = max(ans, sumb - mxb);
        return ans;
    }
};