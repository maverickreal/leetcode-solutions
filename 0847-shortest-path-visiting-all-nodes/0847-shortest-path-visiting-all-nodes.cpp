class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int shortestPathLength(vector<vector<int>>&g) {
        ll n=g.size();
        vi(vi(bool))vis(n, vi(bool)(1<<n, 0));
        list<vi(ll)>l;
        for(ll i=0;i<n;++i){
            l.pb({i, 0, 1<<i});
        }
        ll ans=-1;
        while(!l.empty()){
            vi(ll)nd=l.front();
            l.pop_front();
            if(nd[2]+1==1<<n){
                ans=nd[1];
                break;
            }
            if(vis[nd[0]][nd[2]]){
                continue;
            }
            vis[nd[0]][nd[2]]=1;
            for(ll child : g[nd[0]]){
                if(!vis[child][nd[2]|(1<<child)]){
                    l.pb({child, nd[1]+1, nd[2]|(1<<child)});
                }
            }
        }
        return ans;
    }
};