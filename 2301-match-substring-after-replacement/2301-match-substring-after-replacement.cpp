class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef vector<ll> vi;
    typedef pair<ll, ll> pi;
#define endl '\n'
    static const ll mod = 1e9;
public:
    bool matchReplacement(string& s, string& sub, vector<vector<char>>& m) {
        unordered_map<char, unordered_set<char>>ump;
        for (auto& i : m)
            ump[i[0]].insert(i[1]);
        for (ll i = 0;i <= s.size() - sub.size();i++) {
            bool fl = true;
            ll I = i - 1;
            for (ll j = 0;j < sub.size();++j) {
                ++I;
                if (!(s[I] == sub[j] || ump[sub[j]].find(s[I]) != ump[sub[j]].end())) {
                    fl = false;
                    break;
                }
            }
            if (fl)
                return true;
        }
        return false;
    }
};