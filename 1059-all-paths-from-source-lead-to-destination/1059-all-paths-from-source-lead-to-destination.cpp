class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)vis;
    vi(vi(ll))g;
    bool func(ll nd, const int&dest){
        if(nd==dest){
            return true;
        }
        if(g[nd].empty() || vis[nd]==1){
            return false;
        }
        if(vis[nd]==2){
            return true;
        }
        vis[nd]=1;
        for(ll child:g[nd]){
            if(!func(child, dest)){
                return false;
            }
        }
        vis[nd]=2;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>&e, int src, int dest) {
        vis.assign(n, 0), g.assign(n, {});
        for(auto edge:e){
            g[edge[0]].pb(edge[1]);
        }
        if(!g[dest].empty()){
            return false;
        }
        return func(src, dest);
    }
};
