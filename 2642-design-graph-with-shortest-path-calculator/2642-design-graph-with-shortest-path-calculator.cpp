class Graph {
public:
typedef long long ll;
#define vi(x) vector<x>

vector<vector<pair<ll, ll>>>g;
ll n;

ll shortestPath(ll s, ll dest) { // dijkstra-dense ; for max edges; O(v^2)
        vi(ll)d(n, LLONG_MAX); // dist of the shortest path from src to every node
        bitset<100>vis(0);
        d[s] = 0;
        for (ll i = 0; i < n; i++) {
            ll v = -1;
            for (ll j = 0; j < n; j++) {
                if (!vis[j] && (v == -1 || d[j] < d[v])){
                    v = j;
                }
            }
            if (v==-1 || d[v] == LLONG_MAX){
                break;
            }
            vis[v] = true;
            for (const auto&[to, w] : g[v]) {
                if (d[v] + w < d[to]) {
                    d[to] = d[v] + w;
                }
            }
        }
        return (d[dest]==LLONG_MAX?-1:d[dest]); // path not found 
    }

    Graph(int N, const vi(vi(int))& edges) {
        n=N;
        g.resize(n);
        for(const auto&edge:edges){
            addEdge(edge);
        }
    }
    
    void addEdge(const vi(int)&edge) {
        g[edge[0]].push_back({edge[1], edge[2]});
    }
};