class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
static const char nl = '\n';
class dsu{
public:
    vi(ll)par, size;
    dsu(ll n){
        par.resize(n), size.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll n){
        if(par[n]==n){
            return n;
        }
        return (par[n]=find(par[n]));
    }
    void merge(ll x, ll y){
        ll a=find(x), b=find(y);
        if(a==b){
            return;
        }
        //cout<<x<<' '<<y<<nl;
        if(size[a]<size[b]){
            a+=b, b=a-b, a-=b;
        }
        par[b]=a;
        size[a]+=size[b];
    }
};
public:
    int removeStones(vector<vector<int>>&e) {
        vi(vi(ll))r(10001), c(10001);
        for(ll i=0;i<e.size();++i){
            r[e[i][0]].pb(i), c[e[i][1]].pb(i);
        }
        dsu d(e.size());
        for(ll i=0;i<10001;++i){
            for(ll pos=0, pre=-1;pos<r[i].size();++pos){
                if(pre>-1){
                    d.merge(r[i][pre], r[i][pos]);
                }
                pre=pos;
            }
            for(ll pos=0, pre=-1;pos<c[i].size();++pos){
                if(pre>-1){
                    d.merge(c[i][pre], c[i][pos]);
                }
                pre=pos;
            }
        }
        ll ans=0;
        for(ll i=0;i<e.size();++i){
            ll&sz=d.size[d.find(i)];
            if(sz>1){
                ans+=sz-1;
                sz=1;
            }            
        }
        return ans;
    }
};