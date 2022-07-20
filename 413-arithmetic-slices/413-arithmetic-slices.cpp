class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        ll sz = v.size(), res = 0;
        for (ll i = 0;i < sz - 2;++i) {
            if (v[i + 2] - v[i + 1] != v[i + 1] - v[i]) {
                continue;
            }
            ll j = i + 1;
            for (;j < sz - 1 && v[j + 1] - v[j] == v[j] - v[j - 1];++j);
            res += ((j-i-1)*(j-i))/2;
            i = j - 1;
        }
        return res;
    }
};