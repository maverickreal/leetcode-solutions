class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    vi(vi(ll))dp;
    ll func(const string& s, const string& t, ll i, ll j) {
        if (i == m && j == n) {
            return 0;
        }
        if (i == m) {
            return n - j;
        }
        if (j == n) {
            return m - i;
        }
        if (dp[i][j] == -1) {
            if (s[i] != t[j]) {
                dp[i][j] = min(func(s, t, i + 1, j), func(s, t, i, j + 1));
            }
            else {
                dp[i][j] = func(s, t, i + 1, j + 1);
            }
            ++dp[i][j];
        }
        return dp[i][j];
    }
    string shortestCommonSupersequence(string& s, string& t) {
        m = s.size(), n = t.size();
        dp.assign(m, vi(ll)(n, -1));
        //func(s, t, 0, 0);
        string res;
        ll i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                res.pb(s[i]);
                ++i, ++j;
            }
            else if (func(s, t, i + 1, j) < func(s, t, i, j + 1)) {
                res.pb(s[i++]);
            }
            else {
                res.pb(t[j++]);
            }
        }
        if (i < m) {
            res.append(s.substr(i));
        }
        if (j < n) {
            res.append(t.substr(j));
        }
        return res;
    }
};