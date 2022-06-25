class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
public:
    int countAsterisks(const string& s) {
        ll sz = s.length(), res = 0;
        bool pre = false;
        for (const char& ch : s) {
            if (ch == '|')
                pre = !pre;
            else if (ch == '*' && !pre)
                res++;
        }
        return res;
    }
};