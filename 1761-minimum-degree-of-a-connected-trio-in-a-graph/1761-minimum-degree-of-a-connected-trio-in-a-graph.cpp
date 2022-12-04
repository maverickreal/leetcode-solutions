class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
int minTrioDegree(int n, vector<vector<int>>&e) {
    vi(vi(bool))g(n+1, vi(bool)(n+1));
    vi(ll)cnt(n+1);
    for(const auto&edge:e){
        g[edge[0]][edge[1]]=g[edge[1]][edge[0]]=1;
        ++cnt[edge[0]], ++cnt[edge[1]];
    }
    ll ans=LLONG_MAX;
    for(ll i=1;i<=n;++i){
        for(ll j=i+1;j<=n;++j){
            if(!g[i][j]){
                continue;
            }
            for(ll k=j+1;k<=n;++k){
                if(g[i][k] && g[j][k]){
                    ans=min(ans, cnt[i]+cnt[j]+cnt[k]-6);
                }
            }
        }
    }
    if(ans==LLONG_MAX){
        ans=-1;
    }
    return ans;
}
};