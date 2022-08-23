class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int scoreOfParentheses(const string& s) {
        ll sz = s.length(), o = 0, res = 0;
        for (ll i = 0;i < sz;++i) {
            if (s[i] == '(') {
                ++o;
            }
            else {
                --o;
                if(s[i-1]=='('){
                    res += 1 << o;
                }
            }
        }
        return res;
    }
};