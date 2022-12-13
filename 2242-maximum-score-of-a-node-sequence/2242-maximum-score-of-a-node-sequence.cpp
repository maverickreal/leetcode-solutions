class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int maximumScore(vector<int>&vals, vector<vector<int>>&e) {
        ll n=vals.size(), ans=-1;
        vector<set<pi>>g(n);
        for(const auto&edge:e){
            ll u=edge[0], v=edge[1];
            g[u].insert({vals[v], v}), g[v].insert({vals[u], u});
            if(g[u].size()>3){
                g[u].erase(begin(g[u]));
            }
            if(g[v].size()>3){
                g[v].erase(begin(g[v]));
            }
        }
        for(const auto&edge:e){
            ll u=edge[0], v=edge[1];
            for(const auto&[xVal, x]:g[u]){
                for(const auto&[yVal, y]:g[v]){
                    if(x!=v && x!=y && u!=y){
                        ans=max(ans, vals[u]+vals[v]+xVal+yVal);
                    }
                }
            }
        }
        return ans;
    }
};