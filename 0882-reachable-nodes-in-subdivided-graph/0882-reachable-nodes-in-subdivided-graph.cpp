class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int reachableNodes(const vi(vi(int))&e, ll mx, int n) {
        vi(vi(pi))g(n);
        for(const auto&edge:e){
            g[edge[0]].pb({edge[1], edge[2]});
            g[edge[1]].pb({edge[0], edge[2]});
        }
        vi(ll)d(n, LLONG_MAX);
        d[0] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> q;
        q.push({0, 0});
        vi(vi(ll))usable(n, vi(ll)(n, 0));
        while (!q.empty()) {
            ll v = q.top().second, dist = q.top().first;
            q.pop();
            if (dist != d[v]){
                continue;
            }
            for (auto edge : g[v]) {
                ll to = edge.first, w = edge.second;
                usable[v][to]=min(w, mx-dist);
                if (dist + w + 1 < min(mx+1,d[to])) {
                    d[to] = dist + w + 1;
                    q.push({d[to], to});
                }
            }
        }
        ll ans=0;
        for(const ll&it:d){
            ans+=it<=mx;
        }
        for(const auto&edge:e){
            ans+=min((ll)edge[2], usable[edge[0]][edge[1]]+usable[edge[1]][edge[0]]);
        }
        return ans;
    }
};