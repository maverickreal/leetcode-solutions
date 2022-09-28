class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool validPath(int n, vector<vector<int>>&e, int s, int d) {
        list<ll>l={s};
        vi(bool)vis(n);
        vi(vi(ll))g(n);
        for(auto edge:e){
            g[edge[0]].pb(edge[1]), g[edge[1]].pb(edge[0]);
        }
        while(!l.empty()){
            ll it=l.front();
            l.pop_front();
            vis[it]=true;
            if(it==d){
                return true;
            }
            for(ll child:g[it]){
                if(!vis[child]){
                    l.pb(child);
                }
            }
        }
        return false;
    }
};