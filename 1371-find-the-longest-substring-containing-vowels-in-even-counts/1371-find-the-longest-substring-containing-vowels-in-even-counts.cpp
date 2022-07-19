class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    int findTheLongestSubstring(string& s) {
        ll sz = s.length();
        vi(ll) pos(32, -1);
        unordered_map<char, ll>masks = { {'a',1},{'e',2},{'i',4},{'o',8},{'u',16} };
        ll mask = 0, res = 0;
        for (ll i = 0;i < sz;++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                mask ^= masks[s[i]];
            }
            if (mask && pos[mask] == -1) {
                pos[mask] = i;
            }
            res = max(res, i - pos[mask]);
        }
        return res;
    }
};