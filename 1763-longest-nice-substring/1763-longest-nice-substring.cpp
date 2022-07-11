class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    void check(string& res, string& s) {
        ll szs = s.length(), szr = res.length();
        if (szs <= szr)
            return;
        unordered_set<char>ust;
        for (char ch : s)
            ust.insert(ch);
        for (char ch : s) {
            if (ch >= 'a' && ust.find('A' + ch - 'a') == ust.end())
                return;
            if (ch <= 'Z' && ust.find('a' + ch - 'A') == ust.end())
                return;
        }
        res = s;
    }
    string longestNiceSubstring(string& s) {
        string res;
        for (ll i = 0;i < s.length();++i) {
            string tmp;
            for (ll j = i;j < s.length();++j) {
                tmp.pb(s[j]);
                check(res, tmp);
            }
        }
        return res;
    }
};