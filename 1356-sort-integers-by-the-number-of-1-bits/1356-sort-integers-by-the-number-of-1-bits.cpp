class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    class cmp {
    public:
        bool operator()(const int&A, const int&B) {
            ll a=A, b=B, i = 0, j=0;
            while (a) {
                i += a & 1;
                a >>= 1;
            }
            while (b) {
                j += b & 1;
                b >>= 1;
            }
            return (i == j ? A < B : i < j);
        }
    };
public:
    vector<int> sortByBits(vector<int>& v) {
        sort(v.begin(), v.end(), cmp());
        return v;
    }
};