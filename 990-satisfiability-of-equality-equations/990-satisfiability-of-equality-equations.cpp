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
    bool equationsPossible(vector<string>&v) {
        dsu d(26);
        for(auto e:v){
            if(e[1]=='='){
                d.merge(e[0]-'a', e[3]-'a');
            }
        }
        for(auto e:v){
            if(e[1]=='!' && d.find(e[0]-'a')==d.find(e[3]-'a')){
                    return false;
            }
        }
        return true;
    }
};