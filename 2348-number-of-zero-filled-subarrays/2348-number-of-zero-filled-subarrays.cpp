class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    long long zeroFilledSubarray(vector<int>& v) {
        ll res = 0, sz = v.size();
        for (ll i = 0;i < sz;++i) {
            if(v[i]){
                continue;
            }
            ll j = i;
            for (;j < sz && v[j] == 0;++j);
            --j;
            res += (j - i + 1) * (j - i + 2) / 2;
            i = j;
        }
        return res;
    }
};