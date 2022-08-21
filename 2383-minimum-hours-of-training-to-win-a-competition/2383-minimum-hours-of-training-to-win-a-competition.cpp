class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int minNumberOfHours(int ien, int iex, vector<int>& en, vector<int>& ex) {
        ll n = ex.size(), h = 0;
        for (ll i = 0;i < n;++i) {
            if (en[i] >= ien) {
                h += en[i] - ien + 1;
                ien = en[i] + 1;
            }
            ien -= en[i];
            if (ex[i] >= iex) {
                h += ex[i] - iex + 1;
                iex = ex[i] + 1;
            }
            iex += ex[i];
           // cout << h << ' ' << ien << ' ' << iex << nl;
        }
        return h;
    }
};