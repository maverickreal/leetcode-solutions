class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    void topologicalSort(const vi(vi(ll))&g, vi(int)&v){
        ll n=g.size();
        vi(ll)ind(n);
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
            v.pb(nd);
            for(ll child:g[nd]){
                if(--ind[child]==0){
                    l.pb(child);
                }
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>&g) {
        ll n=g.size();
        vi(vi(ll))rg(n);
        for(ll i=0;i<n;++i){
            for(ll j:g[i]){
                rg[j].pb(i);
            }
        }
        vi(int)ans;
        topologicalSort(rg, ans);
        sort(begin(ans), end(ans));
        return ans;
    }
};