class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool canBeValid(string& s, string& l) {
        ll lo = 0, hi = 0, sz=s.length();
        if(sz&1){
            return false;
        }
        for (ll i = 0;i < sz;++i) {
            if (l[i] == '0') {
                --lo, ++hi;
            }
            else if (s[i] == '(') {
                ++lo, ++hi;
            }
            else {
                --lo, --hi;
            }
            if (hi < 0) {
                return false;
            }
            lo = max(lo, 0LL);
        }
        return (lo == 0);
    }
};