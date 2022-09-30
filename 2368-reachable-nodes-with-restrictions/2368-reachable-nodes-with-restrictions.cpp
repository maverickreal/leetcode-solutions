class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int reachableNodes(int n, vector<vector<int>>&e, vector<int>&r) {
        vi(bool)ust(n, false), vis(n, false);
        for(ll nd:r){
            ust[nd]=true;
        }
        vi(vi(ll))g(n);
        for(auto edge:e){
            g[edge[0]].pb(edge[1]);
            g[edge[1]].pb(edge[0]);
        }
        list<ll>l={0};
        ll ans=0;
        while(!l.empty()){
            ll nd=l.front();
            l.pop_front();
            if(vis[nd]){
                continue;
            }
            ++ans;
            vis[nd]=true;
            for(ll child:g[nd]){
                if(!vis[child] && !ust[child]){
                    l.pb(child);
                }
            }
        }
        return ans;
    }
};