class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef vector<ll> vi;
    typedef pair<ll, ll> pi;
#define endl '\n'
    static const ll mod = 1e9;
public:
    long long countSubarrays(vector<int>& v, long long k) {
        ll sz = v.size(), res = 0;
        vi pre(sz);
        pre[0] = v[0];
        for (ll i = 1;i < sz;i++)
            pre[i] = pre[i - 1] + v[i];
        for (ll i = 0;i < sz;++i) {
            ll l = i,
                r = sz - 1,
                ind = -1;
            while (l <= r) {
                ll mid = l + ((r - l) >> 1);
                ll score = pre[mid] - (i > 0 ? pre[i - 1] : 0);
                score *= mid - i + 1;
                if (score < k) {
                    ind = mid;
                    l = mid + 1;
                    continue;
                }
                r = mid - 1;
            }
            if (ind != -1)
                res += ind - i + 1;
        }
        return res;
    }
};