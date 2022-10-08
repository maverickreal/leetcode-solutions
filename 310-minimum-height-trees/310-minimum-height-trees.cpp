class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>&e) {
        if(n==1){
            return {0};
        }
        vi(vi(ll))g(n);
        vi(ll)ind(n, 0);
        for(auto edge:e){
            g[edge[0]].pb(edge[1]);
            g[edge[1]].pb(edge[0]);
            ++ind[edge[0]], ++ind[edge[1]];
        }
        list<ll>l;
        for(ll i=0;i<n;++i){
            if(ind[i]==1){
                l.pb(i);
            }
        }
        vi(int)ans;
        while(!l.empty()){
            ll sz=l.size();
            ans.clear();
            while(sz--){
                ll nd=l.front();
                l.pop_front();
                ans.pb(nd);
                for(ll child:g[nd]){
                    if(--ind[child]==1){
                        l.pb(child);
                    }
                }
            }
        }
        return ans;
    }
};