class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool connected(const vi(int)&a, const vi(int)&b){
        return (pow(a[2], 2)>=pow(abs(a[0]-b[0]), 2)+pow(abs(a[1]-b[1]), 2));
    }
    int maximumDetonation(vector<vector<int>>&v) {
        ll n=v.size();
        vi(vi(ll))g(n);
        for(ll i=0;i<n;++i){
            for(ll j=i+1;j<n;++j){
                if(connected(v[i], v[j])){
                    g[i].pb(j);
                }
                if(connected(v[j], v[i])){
                    g[j].pb(i);
                }
            }
        }
        vi(bool)vis(n);
        ll ans=0;
        for(ll i=0;i<n;++i){
            if(vis[i]){
                continue;
            }
            vi(bool)ust(n);
            list<ll>l={i};
            vis[i]=ust[i]=true;
            ll res=0;
            while(!l.empty()){
                ll nd=l.front();
                l.pop_front();
                ++res;
                for(ll child:g[nd]){
                    if(!ust[child]){
                        l.pb(child);
                    }
                    ust[child]=true;
                }
            }
            ans=max(ans, res);
        }
        return ans;
    }
};