class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    class dsu{
    public:
        vi(ll)par, size;
        dsu(ll n){
            par.assign(n, 0), size.assign(n, 1);
            for(ll i=0;i<n;++i){
                par[i]=i;
            }
        }
        ll find(ll n){
            if(par[n]==n){
                return n;
            }
            return (par[n]=find(par[n]));
        }
        void merge(ll a, ll b){
            a=find(a), b=find(b);
            if(a==b){
                return;
            }
            if(size[a]<size[b]){
                a+=b, b=a-b, a-=b;
            }
            par[b]=a;
            size[a]+=size[b];
        }
    };
    ll kruskal(const vi(vi(pi))&g){ // adjust for matrix form, or other requirements
        vi(vi(ll))e;
        ll n=g.size(), ans=0;
        for(ll nd=0; nd<n; ++nd){
            for(const pi&child:g[nd]){
                e.pb({nd, child.first, child.second});
            }
        }
        sort(begin(e), end(e), [](const vi(ll)&a, const vi(ll)&b){return (a[2]<b[2]);});
        dsu d(n);
        for(ll i=0;i<e.size();i++){
            if(d.find(e[i][0])!=d.find(e[i][1])){
                d.merge(e[i][0],e[i][1]);
                ans+=e[i][2];
            }
        }
        return ans;
    }
    int minCostToSupplyWater(int n, vector<int>&v, vector<vector<int>>&e) {
        vi(vi(pi))g(n+1);
        for(auto edge:e){
            g[edge[0]].pb({edge[1], edge[2]});
            g[edge[1]].pb({edge[0], edge[2]});
        }
        for(ll i=0;i<n;++i){
            g[0].pb({i+1, v[i]});
        }
        return kruskal(g);
    }
};