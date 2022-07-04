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
    unordered_set<string>ust;
    bool valid(const string& s) {
        ll o = 0, c = 0;
        for (const char& ch : s) {
            if (ch == '(') o++;
            else if (ch == ')')
                c++;
            if (c > o) return false;
        }
        return o == c;
    }

    void func(const string& s, ll i, string& cur) {
        ll sz = s.length();
        if (i == sz) {
            if (valid(cur)) {
                if (ust.empty() || ust.begin()->length() == cur.length())
                    ust.insert(cur);
                else if (ust.begin()->length() < cur.length()) {
                    ust.clear();
                    ust.insert(cur);
                }
            }
            return;
        }
        if (s[i] == '(' || s[i] == ')')
            func(s, i + 1, cur);
        cur.pb(s[i]);
        func(s, i + 1, cur);
        cur.pop_back();
    }
    vector<string> removeInvalidParentheses(string& s) {
        string cur = "";
        func(s, 0, cur);
        return vi(string)(ust.begin(), ust.end());
    }
};