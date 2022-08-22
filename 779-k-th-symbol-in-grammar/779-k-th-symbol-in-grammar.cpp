class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool kthGrammar(int n, int k) {
        if (n == 1) {
            return false;
        }
        bool rec = kthGrammar(n - 1, (k + 1) / 2);
        return (k & 1 ? rec : !rec);
    }
};