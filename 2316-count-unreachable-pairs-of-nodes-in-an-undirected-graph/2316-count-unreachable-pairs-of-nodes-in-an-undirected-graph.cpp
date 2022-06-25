class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define endl '\n'
    const ll mod = 1e9;
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        queue<ll>q;
        vi(vi(ll))g(n);
        for (const auto& it : edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vi(bool)vis(n);
        vi(ll)res;
        for (ll i = 0;i < n;++i) {
            if (vis[i]) continue;
            q.push(i);
            vis[i] = true;
            ll sz = 0;
            while (!q.empty()) {
                ++sz;
                ll cur = q.front();
                q.pop();
                for (const auto& it : g[cur]) {
                    if (vis[it]) continue;
                    q.push(it);
                    vis[it] = true;
                }
            }
            res.push_back(sz);
        }
        ll sum=0;
        for(ll i=res.size()-2;i>-1;--i){
            sum+=res[i]*res[i+1];
            res[i]+=res[i+1];
        }
        // for(ll i:res)
        //     cout<<i<<' ';
        // cout<<endl;
        return sum;
    }
};