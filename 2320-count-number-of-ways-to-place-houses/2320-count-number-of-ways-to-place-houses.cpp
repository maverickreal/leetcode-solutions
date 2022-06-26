class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
public:
    int countHousePlacements(ll n) {
        ll a = 1, b = 1, c = 1, d = 1;// all, none, left, right
        while (--n) {
            ll A = b;
            ll B = ((a + b)%(mod+7) + (c + d)%(mod+7))%(mod+7);
            ll C = (d + b)%(mod+7);
            ll D = (b + c)%(mod+7);
            a = A;
            b = B;
            c = C;
            d = D;
        }
        return ((a + b)%(mod+7) + (c + d)%(mod+7))%(mod+7);
    }
    };