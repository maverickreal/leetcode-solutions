class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(int)) topologicalSort(const vi(vi(ll))&g){
        ll n=g.size();
        vi(ll)ind(n);
        vi(set<ll>)ans(n);
        for(auto it:g){
            for(auto nd:it){
                ++ind[nd];
            }
        }
        list<ll>l;
        for(ll i=0;i<n;++i){
            if(!ind[i]){
                l.pb(i);
            }
        }
        while(!l.empty()){
            ll nd=l.front();
            l.pop_front();
            for(ll child:g[nd]){
                ans[child].insert(nd);
                for(ll i:ans[nd]){
                    ans[child].insert(i);
                }
                if(--ind[child]==0){
                    l.pb(child);
                }
            }
        }
        vi(vi(int))res(n);
        for(ll i=0;i<n;++i){
            res[i]=vi(int)(begin(ans[i]), end(ans[i]));
        }
        return res;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>&e) {
        vi(vi(ll))g(n);
        for(auto edge:e){
            g[edge[0]].pb(edge[1]);
        }
        return topologicalSort(g);
    }
};