class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int wordCount(vector<string>& a, vector<string>& b) {
        ll m = a.size(), n = b.size();
        vi(bool)ust(67108864, false);
        for (string s : a) {
            ll bm = 0;
            for (char ch : s) {
                bm |= 1 << (ch - 'a');
            }
            ust[bm] = true;
        }
        ll ans = 0;
        for (string s : b) {
            ll bm = 0;
            for (char ch : s) {
                bm |= 1 << (ch - 'a');
            }
            for (ll i = 0;i < 26;++i) {
                if (bm & (1 << i) && ust[bm ^ (1 << i)]) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};