// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    typedef int ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
    class cmp {
    public:
        bool operator()(const vi(ll)& a, const vi(ll)& b) {
            return a[2] > b[2];
        }
    };
public:
    int spanningTree(int sz, vector<vector<int>> v[]) {
        priority_queue < vi(ll), vi(vi(ll)), cmp> pq;
        pq.push({ 0, -1, 0 });
        vi(bool)vis(sz);
        ll res = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if (vis[it[0]]) continue;
            vis[it[0]] = true;
            res += it[2];
            for (const auto& ti : v[it[0]]) {
                if (!vis[ti[0]])
                    pq.push({ ti[0], it[0], ti[1] });
            }
        }
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends