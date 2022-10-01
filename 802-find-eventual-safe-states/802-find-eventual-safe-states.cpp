class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)vis;
    ll n;
    bool func(const vi(vi(int))&g, ll nd){
        ll&res=vis[nd];
        if(res==-1){
            res=0;
            bool ans=1;
            for(ll child:g[nd]){
                ans&=func(g, child);
            }
            res=ans;
        }
        return res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>&g) {
        n=g.size();
        vis.assign(n, -1);
        vi(int)res;
        for(ll i=0;i<n;++i){
            if(func(g, i)){
                res.pb(i);
            }
        }
        return res;
    }
};