class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    void topo(const vi(vi(int))&e, const ll&n, vi(ll)&v){
        vi(vi(ll))g(n+1);
        vi(ll)ind(1+n);
        for(const auto&edge:e){
            ++ind[edge[1]];
            g[edge[0]].pb(edge[1]);
        }
        list<ll>l;
        for(ll i=1;i<=n;++i){
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
        if(v.size()!=n){
            v.clear();
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>&rc, vector<vector<int>>&cc) {
        vi(ll)r, c;
        vi(vi(int))ans;
        topo(rc, k, r);
        if(r.empty()){
            return ans;
        }
        topo(cc, k, c);
        if(c.empty()){
            return ans;
        }
        ans.assign(k, vi(int)(k, 0));
        for(ll i=0;i<k;++i){
            ll num=r[i], pos=-1;
            for(ll j=0;j<k;++j){
                if(c[j]==num){
                    pos=j;
                    break;
                }
            }
            ans[i][pos]=num;
        }
        return ans;
    }
};