class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    static bool cmp(const string& a, const string& b) {
        return a.length() < b.length();
    }

    ll sz;
    vi(ll)dp;

    bool compatible(const vi(string)& v, ll i, ll j) {
        ll m = v[i].length(), n = v[j].length();
        if (n - m != 1) {
            return false;
        }
        ll a = 0, b = 0, dif = 0;
        while (a < m && b < n) {
            if (v[i][a] != v[j][b]) {
                if (dif == 1) {
                    return false;
                }
                dif = 1;
            }
            else {
                ++a;
            }
            ++b;
        }
        return true;
    }

    ll func(const vi(string)& v, ll in) {
        if (in >= sz) {
            return 0;
        }
        if (dp[in] == -1) {
            dp[in] = 1;
            for (ll i = in + 1;i < sz;++i) {
                if (compatible(v, in, i)) {
                    dp[in] = max(dp[in], 1 + func(v, i));
                }
            }
        }
        return dp[in];
    }

    int longestStrChain(vector<string>& v) {
        sz = v.size();
        dp.resize(sz, -1);
        sort(v.begin(), v.end(), cmp);
        for (ll i = sz - 1;i > -1;--i) {
            func(v, i);
        }
        // for (ll it : dp) {
        //     cout << it << ' ';
        // }
        // cout << nl;
        // for (string s : v) {
        //     cout << s << ' ';
        // }
        // cout << nl;
        return *max_element(dp.begin(), dp.end());
    }
};