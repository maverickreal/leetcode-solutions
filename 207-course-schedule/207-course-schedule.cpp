class Solution {
typedef long long ll;
typedef pair<string, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool canFinish(int n, vector<vector<int>>&e) {
        vi(vi(ll))g(n);
        vi(ll)ind(n);
        for(auto edge:e){
            g[edge[1]].pb(edge[0]);
            ++ind[edge[0]];
        }
        vi(bool)vis(n);
        ll cnt=0;
        list<ll>l;
        for(ll i=0;i<n;++i){
            if(!ind[i]){
                l.pb(i);
            }
        }
        while(!l.empty()){
            ll nd=l.front();
            l.pop_front();
            if(vis[nd]){
                return false;
            }
            ++cnt;
            vis[nd]=true;
            for(ll child:g[nd]){
                if(!vis[child] && --ind[child]==0){
                    l.pb(child);
                }
            }
        }
        return (cnt==n);
    }
};