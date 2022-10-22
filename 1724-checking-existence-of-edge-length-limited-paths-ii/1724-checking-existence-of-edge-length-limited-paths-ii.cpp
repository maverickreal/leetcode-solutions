class DistanceLimitedPathsExist {
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, vi(ll)> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    class dsu{
    public:
        vi(ll)par, size;
        dsu(ll n){
            par.assign(n, 0), size.assign(n, 1);
            iota(begin(par), end(par), 0);
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
    vi(pi)v;
    ll find(const ll&in, ll n){
        if(v[in].second[n]==n){
            return n;
        }
        return (v[in].second[n]=find(in, v[in].second[n]));
    }
    DistanceLimitedPathsExist(int n, vector<vector<int>>&e) {
        dsu d(n);
        sort(begin(e), end(e), [](const vi(int)&a, const vi(int)&b){return a[2]<b[2];});
        for(ll i=0;i<e.size();++i){
            d.merge(e[i][0], e[i][1]);
            if(i+1==e.size() || e[i][2]!=e[i+1][2]){
                v.pb({e[i][2], d.par});
            }
        }
    }
    
    bool query(int p, int q, int lt) {
        ll l=0, r=v.size()-1, in=-1;
        while(l<=r){
            ll m=l+((r-l)>>1);
            if(v[m].first>=lt){
                r=m-1;
            }
            else{
                in=m, l=m+1;
            }
        }
        return (in>-1 && find(in, p)==find(in, q));
    }
};