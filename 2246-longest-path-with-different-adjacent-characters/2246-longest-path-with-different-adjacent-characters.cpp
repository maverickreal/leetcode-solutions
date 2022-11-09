class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
ll n, res;
vi(vi(ll))g;
ll func(const string&s, ll nd){
    ll mx=0, nxtMx=0;
    for(ll child:g[nd]){
        ll rec=func(s, child);
        if(s[nd]!=s[child]){
            if(rec>mx){
                nxtMx=mx, mx=rec;
            }
            else{
                nxtMx=max(nxtMx, rec);
            }
        }
    }
    res=max(res, mx+1+nxtMx);
    return mx+1;
}
    int longestPath(vector<int>&p, const string&s) {
        n=s.size(), res=0, g.resize(n);
        for(ll i=1;i<n;++i){
            g[p[i]].pb(i);
        }
        func(s, 0);
        return res;
    }
};