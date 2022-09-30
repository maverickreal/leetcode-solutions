class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int maximalNetworkRank(int n, vector<vector<int>>&e) {
        vi(unordered_set<ll>)g(n);
        for(auto edge:e){
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        ll ans=0;
        for(ll i=0;i<n;++i){
            for(ll j=i+1;j<n;++j){
                ll res=g[i].size()+g[j].size();
                if(g[i].find(j)!=g[i].end()){
                    --res;
                }
                ans=max(ans, res);
            }
        }
        return ans;
    }
};