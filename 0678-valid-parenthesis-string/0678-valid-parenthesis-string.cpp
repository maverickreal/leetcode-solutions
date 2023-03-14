class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool checkValidString(const string& s) {
        ll l = 0, h = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++l, ++h;
            }
            else if (ch == ')') {
                --l, --h;
            }
            else {
                --l, ++h;
            }
            if (h < 0) {
                return false;
            }
            l=max(l, 0LL);
        }
        return (l==0);
    }
};