class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int rangeBitwiseAnd(ll left, ll right) {
        ll ans = 0;
        for (ll i = 31;i > -1;--i) {
            if (right & (1 << i)) {
                ll num = (right ^ (1 << i)) | ((1 << i) - 1);
                if (num < left) {
                    ans |= 1 << i;
                }
            }
        }
        return ans;
    }
};