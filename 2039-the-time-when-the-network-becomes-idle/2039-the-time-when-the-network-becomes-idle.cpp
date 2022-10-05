class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll func(ll p, ll nd, ll d){
        if(p>=d){
            return d+1;
        }
        ll cnt=(d-p)/p;
        if((d-p)%p){
            ++cnt;
        }
        return cnt*p+d+1;
    }
    int networkBecomesIdle(vector<vector<int>>&e, vector<int>&p) {
        ll n=p.size();
        vi(vi(ll))g(n);
        for(auto edge:e){
            g[edge[0]].pb(edge[1]);
            g[edge[1]].pb(edge[0]);
        }
        list<ll>l={0};
        vi(bool)vis(n);
        ll ans=0, d=-1;
        while(!l.empty()){
            ++d;
            ll sz=l.size();
            while(sz--){
                ll it=l.front();
                l.pop_front();
                if(vis[it]){
                    continue;
                }
                if(it){
                    ans=max(ans, func(p[it], it, d*2));
                }
                vis[it]=true;
                for(ll ti:g[it]){
                    if(!vis[ti]){
                        l.pb(ti);
                    }
                }
            }
        }
        return ans;
    }
};