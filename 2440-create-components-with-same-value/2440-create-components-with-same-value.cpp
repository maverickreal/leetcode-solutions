class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n, rem, sum;
    vi(vi(ll))g;
    ll func(const vi(vi(ll))&g, const vi(int)&val, const ll&nd, const ll&par){
        ll tot=val[nd];
        for(ll child:g[nd]){
            if(child!=par){
                tot+=func(g, val, child, nd);
            }
        }
        if(tot==sum){
            --rem, tot=0;
        }
        return tot;
    }
    int componentValue(vector<int>&v, vector<vector<int>>&e) {
        n=v.size();
        ll tot=accumulate(begin(v), end(v), 0LL), ans=0;
        g.resize(n);
        for(auto edge:e){
            g[edge[0]].pb(edge[1]);
            g[edge[1]].pb(edge[0]);
        }
        for(ll i=1;i<=n;++i){
            if(tot%i){
                continue;
            }
                rem=i, sum=tot/rem;
                func(g, v, 0, -1);
                if(rem==0){
                    ans=i;
                }
        }
        return ans-1;
    }
};