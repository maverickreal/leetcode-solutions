class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n, ans;
    vi(ll)par, size;
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
        --ans;
        if(size[a]<size[b]){
            a^=b, b^=a, a^=b;
        }
        par[b]=a;
        size[a]+=size[b];
    }
    int findCircleNum(vector<vector<int>>&v) {
        n=v.size(), ans=n;
        size.assign(n, 1), par.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        for(ll i=0;i<n;++i){
            for(ll j=i+1;j<n;++j){
                if(v[i][j]){
                    merge(i, j);
                }
            }
        }
        return ans;
    }
};