class Solution {
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
    ll getBitMask(const string&s){
        ll ans=0;
        for(char ch:s){
            ans|=1<<(ch-'a');
        }
        return ans;
    }
    vector<int> groupStrings(vector<string>&v) {
        n=v.size();
        unordered_map<ll,ll>ump;
        par.resize(n), size.assign(n, 1);
        iota(begin(par), end(par), 0);
        for(ll i=0;i<n;++i){
            ll bm=getBitMask(v[i]);
            if(ump.find(bm)!=ump.end()){
                merge(i, ump[bm]);
            }
            for(ll j=0;j<26;++j){
                if(ump.find(bm^(1<<j))!=ump.end()){
                    merge(ump[bm^(1<<j)], i);
                }
            }
            for(ll z=0;z<26;++z){
                if((bm>>z)&1){
                    continue;
                }
                for(ll o=0;o<26;++o){
                    if(!((bm>>o)&1)){
                        continue;
                    }
                    if(ump.find(bm^(1<<z)^(1<<o))!=ump.end()){
                        merge(ump[bm^(1<<z)^(1<<o)], i);
                    }
                }
            }
            ump[bm]=i;
        }
        int cnt=0, mx=0;
        for(ll i=0;i<n;++i){
            mx=max(mx, (int)size[i]);
            cnt+=par[i]==i;
            //cout<<i<<' '<<par[i]<<' '<<size[i]<<nl;
        }
        return {cnt, mx};
    }
};