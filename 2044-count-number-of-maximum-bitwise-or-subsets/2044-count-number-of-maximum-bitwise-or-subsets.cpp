class Solution {
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int countMaxOrSubsets(vector<int>& v) {
        vi(ll)seq = { 0 };
        ll res = 0, totor = 0;
        for (ll it : v)
            totor |= it;
        for (ll it : v) {
            ll sz = seq.size();
            for (ll i = 0;i < sz;++i) {
                ll itor = seq[i] | it;
                seq.pb(itor);
                if (itor == totor)
                    ++res;
            }
        }
        return res;
    }
};