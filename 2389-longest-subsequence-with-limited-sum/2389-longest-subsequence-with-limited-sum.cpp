class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll bs(const vi(int)& v, ll x) {
        ll l = 0, r = v.size() - 1, ans = -1;
        while (l <= r) {
            ll m = l + ((r - l) >> 1);
            if (v[m] <= x) {
                ans = m, l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;
    }
    vector<int> answerQueries(vector<int>& v, vector<int>& q) {
        ll vs = v.size(), qs = q.size();
        vi(int)ans(qs, 0);
        sort(v.begin(), v.end());
        for (ll i = 1;i < vs;++i) {
            v[i] += v[i - 1];
        }
        for (ll i = 0;i < qs;++i) {
            ans[i] = bs(v, q[i]) + 1;
        }
        return ans;
    }
};