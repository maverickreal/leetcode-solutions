class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)vis;
    bool func(const vi(vi(ll))&g, ll nd){ // detect cycle
        if(vis[nd]==1){
            return 1;
        }
        if(vis[nd]==2){
            return 0;
        }
        vis[nd]=1;
        for(ll child:g[nd]){
            if(func(g, child)){
                return 1;
            }
        }
        vis[nd]=2;
        return 0;
    }
    bool isPrintable(vector<vector<int>>&v) {
        vi(vi(ll))g(61);
        ll m=v.size(), n=v[0].size();
        for(ll i=1;i<=60;++i){
            ll mnx=m, mny=n, mxx=-1, mxy=-1; //  min, max, x, y, blah blah...
            for(ll j=0;j<m;++j){
                for(ll k=0;k<n;++k){
                    if(v[j][k]==i){
                        mnx=min(mnx, j), mny=min(mny, k), mxx=max(mxx, j), mxy=max(mxy, k);
                    }
                }
            }
            for(ll r=mnx;r<=mxx;++r){
                for(ll c=mny;c<=mxy;++c){
                    if(v[r][c]!=i){
                        g[i].pb(v[r][c]);
                    }
                }
            }
        }
        vis.assign(61, 0);
        for(ll nd=1;nd<=60;++nd){
            if(!vis[nd] && func(g, nd)){
                return false;
            }
        }
        return true;
    }
};