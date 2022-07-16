class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int largestCombination(vector<int>& v) {
        ll sz = v.size(), res = 0;
        while (true) {
            bool fl = true;
            ll ans = 0;
            for (ll& it : v) {
                if (it)
                    fl = false;
                if (it & 1)
                    ans++;
                it >>= 1;
            }
            res = max(res, ans);
            if (fl)
                break;
        }
        return res;
    }
};