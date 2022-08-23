class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string removeOuterParentheses(const string& s) {
        ll sz = s.length(), pre = 0, o = 0, z = 0;
        string res;
        for (ll i = 0;i < sz;++i) {
            if (s[i] == '(') {
                ++o;
            }
            else {
                ++z;
            }
            if (o == z) {
                pre = i + 1;
            }
            else if(i!=pre) {
                res.pb(s[i]);
            }
        }
        return res;
    }
};