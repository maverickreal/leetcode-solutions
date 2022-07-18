class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll sz;
    unordered_set<string>ust;
    vi(vi(ll))dp;
    bool func(const string& s, ll in, ll pre) {
        if (in == sz) {
            return (pre == sz || ust.find(s.substr(pre, sz - pre)) != ust.end());
        }
        if (dp[in][pre] == -1) {
            if (func(s, in + 1, pre)) {
                dp[in][pre] = 1;
            }
            else {
                dp[in][pre] = (ust.find(s.substr(pre, in - pre + 1)) != ust.end() && func(s, in + 1, in + 1) == 1);
            }
        }
        return dp[in][pre];
    }
    bool wordBreak(string& s, vector<string>& v) {
        sz = s.length();
        dp.resize(sz, vi(ll)(sz, -1));
        for (string& s : v)
            ust.insert(s);
        return func(s, 0, 0);
    }
};