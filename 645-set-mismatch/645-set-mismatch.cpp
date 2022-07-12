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
    vector<int> findErrorNums(vector<int>& v) {
        vi(ll)res(2);
        for (ll I : v) {
            ll i=abs(I);
            if (v[i - 1] < 0)
                res[0] = i;
            else
                v[i - 1] = -v[i - 1];
        }
        for (ll i = 0;i < v.size();i++) {
            if (v[i] > 0)
                res[1] = i + 1;
        }
        return res;
    }
};