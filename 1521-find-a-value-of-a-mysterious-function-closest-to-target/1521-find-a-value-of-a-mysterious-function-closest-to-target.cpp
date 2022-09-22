class Solution {
    typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int closestToTarget(vector<int>&v, ll k) {
        ll sz=v.size(), res=LLONG_MAX;
        vi(unordered_set<ll>)ump(sz);
        ump[sz-1].insert(v[sz-1]);
        for(ll i=sz-2;i>-1;--i){
            res=min(res, abs(k-ll(v[i])));
            ump[i].insert(v[i]);
            for(ll it:ump[i+1]){
                ump[i].insert(it&v[i]);
                res=min(res, abs(k-(it&v[i])));
            }
        }
        return min(res, abs(k-v[sz-1]));
    }
};