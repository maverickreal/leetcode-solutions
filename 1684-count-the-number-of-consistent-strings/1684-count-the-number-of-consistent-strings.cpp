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
    int countConsistentStrings(string& s, vector<string>& v) {
        ll ump = 0, ans = v.size();
        for (char ch : s)
            ump |= (1 << (ch - 'a'));
        for (string& str : v) {
            ll cmp = 0, res = 0;
            for (char ch : str)
                cmp |= (1 << (ch - 'a'));
            ll tmp = ump;
            while (tmp && cmp) {
                if (!(tmp & 1) && (cmp & 1)) {
                    res = -1;
                    break;
                }
                tmp >>= 1;
                cmp >>= 1;
            }
            if (cmp)
                res = -1;
            ans += res;
        }
        return ans;
    }
};