class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string reverseParentheses(const string& s) {
        ll sz = s.length();
        list<string>l;
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                if (l.empty() || l.back()=="(") {
                    string str;
                    str.pb(ch);
                    l.pb(str);
                }
                else {
                    l.back().pb(ch);
                }
            }
            else if (ch == '(') {
                string str;
                str.pb(ch);
                l.pb(str);
            }
            else {
                string str;
                while (l.back() != "(") {
                    string tmp=l.back();
                    reverse(tmp.begin(), tmp.end());
                    str.append(tmp);
                    l.pop_back();
                }
                l.pop_back();
                l.pb(str);
            }
        }
        string str;
        while(!l.empty()){
            string tmp=l.back();
            l.pop_back();
            reverse(tmp.begin(), tmp.end());
            str.append(tmp);
        }
        reverse(str.begin(), str.end());
        return str;
    }
};