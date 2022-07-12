class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    ll mod = 1e9 + 7;
    char nl = '\n';
public:
    ll sz;
    vi(ll)dp;
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(0);
        for (int i = 0; i < 32; i++) {
            b[i] = n & 1;
            n >>= 1;
        }
        uint32_t res = 0;
        for (ll i = 0;i < 16;++i) {
            bool tmp = b[i];
            b[i] = b[31 - i];
            b[31 - i] = tmp;
        }
        for (ll i = 0;i < 32;++i)
            res |= b[i] << i;
        return res;
    }
};