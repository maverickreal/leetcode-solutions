class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int countTriplets(vector<int>& v) {
        vi(ll)ump(1 << 16, 0); // max possible size, as the b.w. & of {x,y} can never be greater than max(x,y) 
        for (ll it : v) {
            for (ll ti : v) {
                ++ump[it & ti]; // ump[i]=j =>  j pairs {x,y} in total such that x&y==i
            }
        }
        ll ans = 0;
        for (ll it : v) {
            for (ll in = 0;in < ump.size();++in) {
                if ((in & it) == 0) {
                    ans += ump[in]; // here goes nothing
                }
            }
        }
        return ans;
    }
};