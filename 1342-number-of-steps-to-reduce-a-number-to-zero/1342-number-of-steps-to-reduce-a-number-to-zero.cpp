class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';

public:
    int numberOfSteps(int num) {
        ll res = 0;
        while (num) {
            ++res;
            if (num & 1)
                --num;
            else
                num >>= 1;
        }
        return res;
    }
};