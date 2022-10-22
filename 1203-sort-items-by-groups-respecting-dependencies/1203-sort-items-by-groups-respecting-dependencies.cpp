class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    void topo(const vi(vi(ll))&g, vi(ll)&ind, vi(ll)&v){
        list<ll>l;
        ll n=ind.size();
        for(ll i=0;i<n;++i){
            if(!ind[i]){
                l.pb(i);
            }
        }
        vi(bool)vis(n);
        while(!l.empty()){
            ll nd=l.front();
            l.pop_front();
            if(vis[nd]){
                continue;
            }
            v.pb(nd);
            vis[nd]=1;
            for(ll child:g[nd]){
                if(!vis[child] && --ind[child]==0){
                    l.pb(child);
                }
            }
        }
    }
    vector<int> sortItems(int n, int m, vector<int>&b, vector<vector<int>>&pre) {
        ll x=m;
        for(ll i=0;i<n;++i){
            if(b[i]==-1){
                b[i]=x++;
            }
        }
        vi(vi(ll))gb(x), gi(n);
        vi(ll)indi(n), indb(x);
        for(ll i=0;i<n;++i){
            for(ll j:pre[i]){
                gi[j].pb(i);
                if(b[j]!=b[i]){
                    gb[b[j]].pb(b[i]);
                    ++indb[b[i]];
                }
            }
            indi[i]=pre[i].size();
        }
        vi(ll)topi, topb;
        topo(gi, indi, topi), topo(gb, indb, topb);
        if(topi.size()!=n || topb.size()!=x){
            return {};
        }
        gb.assign(x, {});
        for(ll it:topi){
            gb[b[it]].pb(it);
        }
        vi(int)ans;
        for(ll i=0;i<topb.size();++i){
            for(ll it:gb[topb[i]]){
                ans.pb(it);
            }
        }
        return ans;
    }
};