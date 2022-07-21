class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int singleNumber(vector<int>& v) {
        ll sz = v.size(), tn = LLONG_MAX, tn1 = 0, tn2 = 0;
        for (ll it : v) {
            ll cmn = tn & it, cmn1 = tn1 & it, cmn2 = tn2 & it;
            tn &= ~cmn;
            tn1 |= cmn;
            tn1 &= ~cmn1;
            tn2 |= cmn1;
            tn2 &= ~cmn2;
            tn |= cmn2;
        }
        return tn1;
    }
};