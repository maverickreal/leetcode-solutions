class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll m, n, ans;
    vi(ll)par, size;
    ll find(ll x){
        if(par[x]==x){
            return x;
        }
        return (par[x]=find(par[x]));
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
    ll getCellInd(ll i, ll j, ll id){
        return (i*m + j)*4 + id;
    }
    int regionsBySlashes(vector<string>&v) {
        m=v.size(), n=m*m*4, ans=n;
        par.assign(n, 0), size.assign(n, 1);
        for(ll i=0;i<n;++i){
            par[i]=i;
        }
        for(ll i=0;i<m;++i){
            for(ll j=0;j<m;++j){
                if(i>0){
                    merge(getCellInd(i-1, j, 2), getCellInd(i, j, 0));
                }
                if(j>0){
                    merge(getCellInd(i, j-1, 1), getCellInd(i, j, 3));
                }
                if(v[i][j]==' '){
                    merge(getCellInd(i, j, 0), getCellInd(i, j, 1)), merge(getCellInd(i, j, 1), getCellInd(i, j, 2)), merge(getCellInd(i, j, 2), getCellInd(i, j, 3)), merge(getCellInd(i, j, 3), getCellInd(i, j, 0));
                }
                else if(v[i][j]=='/'){
                    merge(getCellInd(i, j, 3), getCellInd(i, j, 0)), merge(getCellInd(i, j, 1), getCellInd(i, j, 2));
                }
                else{
                    merge(getCellInd(i, j, 0), getCellInd(i, j, 1)), merge(getCellInd(i, j, 2), getCellInd(i, j, 3));
                }
            }
        }
        return ans;
    }
};