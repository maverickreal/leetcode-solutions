class Solution {
typedef long long ll;
typedef long double ld;
typedef pair<ll, ld> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
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
        if(size[a]<size[b]){
            a+=b, b=a-b, a-=b;
        }
        par[b]=a;
        size[a]+=size[b];
    }
    int makeConnected(int n, vector<vector<int>>&e) {
        if(e.size()<n-1){
            return -1;
        }
        par.resize(n), size.assign(n, 1);
        iota(par.begin(), par.end(), 0);
        for(auto edge:e){
            merge(edge[0], edge[1]);
        }
        ll ans=0;
        for(ll i=0;i<n;++i){
            if(par[i]==i){
                ++ans;
            }
            //cout<<i<<' '<<par[i]<<nl;
        }
        return ans-1;
    }
};