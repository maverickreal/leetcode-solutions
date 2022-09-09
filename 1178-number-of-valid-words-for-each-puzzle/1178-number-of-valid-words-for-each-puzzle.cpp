class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    unordered_map<ll,ll>ump;
    ll func(const string& s) {
        ll ans = ump[1<<(s[0]-'a')], sz = s.size(), mask = bm(s.substr(1));
        for (ll sm = mask;sm > 0;sm = (sm - 1) & mask) {
            ans += ump[sm | (1 << (s[0] - 'a'))];
        }
        return ans;
    }
    ll bm(const string& s) {
        ll ans = 0;
        for (char ch : s) {
            ans |= 1 << (ch - 'a');
        }
        return ans;
    }
    vector<int> findNumOfValidWords(vector<string>& w, vector<string>& p) {
        for (string s : w) {
            ++ump[bm(s)];
        }
        vi(int)res(p.size());
        for (ll i = 0;i < p.size();++i) {
            res[i] = func(p[i]);
        }
        return res;
    }
};