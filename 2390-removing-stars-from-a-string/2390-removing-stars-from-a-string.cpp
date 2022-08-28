class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string removeStars(string& s) {
        list<char>st;
        ll sz = s.length();
        for (char ch : s) {
            if (ch == '*') {
                st.pop_back();
            }
            else {
                st.push_back(ch);
            }
        }
        return string(st.begin(), st.end());
    }
};