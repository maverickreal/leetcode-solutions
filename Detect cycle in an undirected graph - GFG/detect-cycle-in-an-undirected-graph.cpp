// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    typedef int ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int sz, vector<ll>v[]) {
        vi(bool)vis(sz);
        for (ll i = 0;i < sz;++i) {
            if (vis[i])continue;
            queue<pi>q;
            q.push({ i, -1 });
            vis[i] = true;
            while (!q.empty()) {
                pi it = q.front();
                q.pop();
                for (const auto& ti : v[it.first]) {
                    if (ti == it.second)continue;
                    if (vis[ti])return true;
                    vis[ti] = true;
                    q.push({ ti, it.first });
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends