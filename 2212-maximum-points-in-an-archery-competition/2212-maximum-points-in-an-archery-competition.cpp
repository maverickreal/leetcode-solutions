class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> maximumBobPoints(int n, vector<int>& v) {
        ll res = -1, resMax = -1;
        for (ll i = 0;i < (1 << 12);++i) {
            ll sum = 0, score = 0;
            for (ll j = 0;j < 12;++j) {
                if (i & (1 << j)) {
                    sum += v[j] + 1;
                    score += j;
                }
            }
            if (sum <= n && score >= resMax) {
                resMax = score;
                res = i;
            }
        }
        for (ll i = 0;i < 12;++i) {
            if (res & (1 << i)) {
                ++v[i];
            }
            else {
                v[i] = 0;
            }
        }
        v.back() += n - accumulate(v.begin(), v.end(), 0);
        return v;
    }
};