class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    void floydWarshall(vi(vi(ll))&g){
        ll n=g.size();
        for(ll k=0;k<n;++k){
            for(ll i=0;i<n;++i){
                for(ll j=0;j<n;++j){
                    if(g[i][k]<LLONG_MAX && g[k][j]<LLONG_MAX){
                        g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
                    }
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>&e, const ll k) {
        vi(vi(ll))g(n, vi(ll)(n, LLONG_MAX));
        for(auto edge:e){
            g[edge[0]][edge[1]]=g[edge[1]][edge[0]]=edge[2];
        }
        for(ll i=0;i<n;++i){
            g[i][i]=0;
        }
        floydWarshall(g);
        ll city=-1, count=LLONG_MAX;
        for(ll i=n-1;i>-1;--i){
            ll cnt=0;
            for(ll j:g[i]){
                cnt+=j<=k;
            }
            if(cnt<count){
                count=cnt, city=i;
            }
        }
        return city;
    }
};