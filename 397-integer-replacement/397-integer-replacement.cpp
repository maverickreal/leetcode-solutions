class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:

    ll integerReplacement(ll n) {
        if (n < 3) {
            return n - 1;
        }
        if ((n & 1) == 0) {
            return 1+integerReplacement(n >> 1);
        }
        return 1+min(integerReplacement(n - 1), integerReplacement(n + 1));
    }
};