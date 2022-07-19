class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    int minFlips(int a, int b, int c) {
        ll res = 0;
        while (a || b || c) {
            if (c & 1) {
                if (!(a & 1 || b & 1)) {
                    ++res;
                }
            }
            else {
                res += a & 1;
                res += b & 1;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return res;
    }
};