class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))g;
    ll n;
    vi(int)res, cnt;
    void dfs1(ll nd, ll par){
        for(ll child:g[nd]){
            if(child!=par){
                dfs1(child, nd);
                cnt[nd]+=cnt[child];
                res[nd]+=res[child]+cnt[child];
            }
        }
    }
    void dfs2(ll nd, ll par){
        for(ll child:g[nd]){
            if(child!=par){
                res[child]=res[nd]+n-2*cnt[child];
                dfs2(child, nd);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>&e) {
        n=N;
        g.resize(n), res.assign(n, 0), cnt.assign(n, 1);
        for(const auto&edge:e){
            g[edge[0]].pb(edge[1]), g[edge[1]].pb(edge[0]);
        }
        dfs1(0, -1), dfs2(0, -1);
        return res;
    }
};