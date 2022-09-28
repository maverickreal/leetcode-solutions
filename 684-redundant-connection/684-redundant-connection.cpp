class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(ll)par, size;
    ll find(ll n){
        if(par[n]==n){
            return n;
        }
        return (par[n]=find(par[n]));
    }
    bool merge(ll a, ll b){
        a=find(a), b=find(b);
        if(a==b){
            return true;
        }
        if(size[a]<size[b]){
            a^=b, b^=a, a^=b;
        }
        par[b]=a;
        size[a]+=size[b];
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>&e) {
        n=e.size();
        par.assign(n, 0), size.assign(n, 1);
        iota(par.begin(), par.end(), 0);
        vi(int)ans;
        for(auto edge : e){
            if(merge(edge[0]-1, edge[1]-1)){
                ans=edge;
                break;
            }
        }
        return ans;
    }
};