class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    class cmp{
    public:
        bool operator()(const vi(ll)&a, const vi(ll)&b){
            return (a[1]>b[1]);
        }
    };
    vi(vi(ll))vis;
    vi(vi(pi))g;
    ll n, s, d;
    ll dijkstraSparse() {
        priority_queue<vi(ll), vi(vi(ll)), cmp> q;
        q.push({s, 0, 0});
        while (!q.empty()) {
            ll v = q.top()[0], dist = q.top()[1], disc=q.top()[2];
            q.pop();
            if (dist>vis[v][disc]){
                continue;
            }
            if(v==n-1){
                return dist;
            }
            for (auto edge : g[v]) {
                ll to = edge.first, w = edge.second;
                if (dist + w < vis[to][disc]) {
                    vis[to][disc] = dist + w;
                    q.push({to, dist+w, disc});
                }
                if(disc<d && dist+w/2<vis[to][disc+1]){
                    vis[to][disc+1]=dist+w/2;
                    q.push({to, dist+w/2, disc+1});
                }
            }
        }
        return -1;
    }
    int minimumCost(int N, vector<vector<int>>&e, int D) {
        n = N, d=D, s=0;
        g.resize(n), vis.assign(n, vi(ll)(d+1, LLONG_MAX));
        vis[0][0]=0;
        for(auto edge:e){
            g[edge[0]].pb({edge[1], edge[2]});
            g[edge[1]].pb({edge[0], edge[2]});
        }
        return dijkstraSparse();
    }
};