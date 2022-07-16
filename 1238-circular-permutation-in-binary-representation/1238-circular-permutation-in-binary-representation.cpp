class Solution {
        typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> circularPermutation(int n, int start) {
        vi(ll)res, v = { 0, 1 };
        for (ll i = 2;i <= n;++i) {
            ll it = (1 << (i - 1));
            for (ll j = v.size() - 1;j > -1;--j) {
                v.pb(it ^ v[j]);
            }
        }
        ll in=-1;
        for(ll i=0;i<v.size();++i){
            if(v[i]==start){
                in=i;
                break;
            }
        }
        res=vi(ll)(v.begin()+in, v.end());
        for(ll i=0;i<in;++i)
            res.pb(v[i]);
        return res;
    }
};