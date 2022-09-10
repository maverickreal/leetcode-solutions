class Solution {
    typedef long long ll;
    typedef pair<ll, char> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n;
    unordered_set<string>ust;
    vi(vi(vi(ll)))dp;
    vi(ll)func(const string& s, ll in, ll pre) {
        if (in == m) {
            return (pre == m ? vi(ll) { 0 } : vi(ll)());
        }
        vi(ll)& v = dp[in][pre];
        if (v == vi(ll) { -1 }) {
            v = func(s, in + 1, pre);
            if (ust.find(s.substr(pre, in - pre + 1)) != ust.end()) {
                for (auto it : func(s, in + 1, in + 1)) {
                    v.pb(it | (1LL << in));
                }
            }
        }
        return v;
    }
    vector<string> wordBreak(string& s, vector<string>& v) {
        m = s.size(), n = v.size();
        for (string str : v) {
            ust.insert(str);
        }
        dp.assign(m, vi(vi(ll))(m, { -1 }));
        vi(ll) res = func(s, 0, 0);
        vi(string)ans;
        for (ll it : res) {
            string str;
            for (ll i = 0;i < m;++i) {
                str.pb(s[i]);
                if ((it >> i) & 1) {
                    str.pb(' ');
                }
            }
            if (str.back() == ' ') {
                str.pop_back();
            }
            ans.pb(str);
        }
        return ans;
    }
};