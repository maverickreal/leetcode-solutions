class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))g;
    vi(bool)vis;
    ll func(){
        ll ans=0;
        list<ll>l={0};
        while(!l.empty()){
            ll nd=l.front();
            l.pop_front();
            if(vis[abs(nd)]){
                continue;
            }
            vis[abs(nd)]=true;
            ans+=nd>0;
            for(ll child:g[abs(nd)]){
                if(!vis[abs(child)]){
                    l.pb(child);
                }
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>&v) {
        g.assign(n, {}), vis.assign(n, false);
        for(auto e:v){
            g[e[0]].pb(e[1]);
            g[e[1]].pb(-e[0]);
        }
        return func();
    }
};