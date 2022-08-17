class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int flipLights(int n, int p) {
        if (p == 0) {
            return 1;
        }
        if (n == 1) {
            return 2;
        }
        if (n == 2) {
            return 3 + (p > 1);
        }
        if (p == 1) {
            return 4;
        }
        if (p == 2) {
            return 7;
        }
        return 8;
    }
};