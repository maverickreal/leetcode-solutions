class Solution {
typedef long long ll;
typedef long double ld;
typedef pair<ll, ld> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(ll))g;
    vi(int)ans;
    vi(bool)vis;
    ll func(ll nd, const vi(int)&q){
        int&res=ans[nd];
        if(vis[nd]){
            return res;
        }
        vis[nd]=true;
        for(ll child:g[nd]){
            // if(vis[child]){
            //     continue;
            // }
            //vis[child]=true;
            ll rec=func(child, q);
            if(q[rec]<q[res]){
                res=rec;
            }
        }
        //cout<<nd<<' '<<res<<nl;
        return res;
    }
    vector<int> loudAndRich(vector<vector<int>>&e, vector<int>&q) {
        n=q.size();
        g.resize(n), ans.resize(n), vis.assign(n, false);
        for(auto edge:e){
            g[edge[1]].pb(edge[0]);
        }
        iota(begin(ans), end(ans), 0);
        for(ll i=0;i<n;++i){
            if(!vis[i]){
                //vis[i]=true;
                func(i, q);
            }
        }
        return ans;
    }
};