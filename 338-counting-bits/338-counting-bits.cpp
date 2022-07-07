class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> countBits(int n) {
        vi(int)res(n + 1);
        for (ll i = 1;i <= n;++i) {
            res[i] = res[i - 1];
            ll pre = i - 1;
            while (pre & 1) {
                --res[i];
                pre >>= 1;
            }
            ++res[i];
        }
        return res;
    }
};