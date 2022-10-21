class Solution {
typedef int ll;
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
    ll kruskal(ll n, const vi(vi(int))&e, ll dont, ll take){
        ll ans=0;
        dsu d(n);
        if(take>-1){
            d.merge(e[take][0], e[take][1]);
            ans+=e[take][2];
        }
        for(ll i=0;i<e.size();i++){
            if(i!=dont && i!=take && d.find(e[i][0])!=d.find(e[i][1])){
                d.merge(e[i][0],e[i][1]);
                ans+=e[i][2];
            }
        }
        ll cnt=0;
        for(ll i=0;i<n;++i){
            if(d.par[i]==i){
                ++cnt;
            }
        }
        if(cnt!=1){
            ans=INT_MAX;
        }
        return ans;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>&e) {
        for(ll i=0;i<e.size();++i){
            e[i].pb(i);
        }
        sort(begin(e), end(e), [](const vi(int)&a, const vi(int)&b){return (a[2]<b[2]);});
        unordered_set<ll>crit, sudo;
        ll wtTotal=kruskal(n, e, -1, -1);
        cout<<wtTotal<<' ';
        for(ll i=0;i<e.size();++i){
            ll wtDont=kruskal(n, e, i, -1);
            if(e[i][3]==3){
                cout<<wtDont<<' ';
            }
            if(wtDont>wtTotal){
                crit.insert(e[i][3]);
            }
            else{
                ll wtTake=kruskal(n, e, -1, i);
                if(e[i][3]==3){
                    cout<<wtTake<<' ';
                }
                if(wtTake==wtTotal){
                    sudo.insert(e[i][3]);
                }
            }
        }
        return vi(vi(int))({vi(int)(begin(crit), end(crit)), vi(int)(begin(sudo), end(sudo))});
    }
};