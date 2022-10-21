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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>&e, vector<vector<int>>&q) {
        for(ll i=0;i<q.size();++i){
            q[i].pb(i);
        }
        sort(begin(q), end(q), [](const vi(int)&a, const vi(int)&b){return a[2]<b[2];});
        sort(begin(e), end(e), [](const vi(int)&a, const vi(int)&b){return a[2]<b[2];});
        vi(bool)ans(q.size(), 0);
        dsu d(n);
        ll in=0;
        for(ll i=0;i<q.size();++i){
            for(;in<e.size() && e[in][2]<q[i][2];++in){
                d.merge(e[in][0], e[in][1]);
            }
            ans[q[i][3]]=d.find(q[i][0])==d.find(q[i][1]);
        }
        return ans;
    }
};