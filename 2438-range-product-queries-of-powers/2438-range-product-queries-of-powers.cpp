class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<int> productQueries(int n, vector<vector<int>>&q) {
        vi(ll)p;
        for(ll i=0, N=n;N>0;++i){
            if((N>>i)&1){
                p.pb(1<<i);
                N^=1<<i;
            }
        }
        ll sz=q.size();
        vi(int)ans(sz, 1);
        for(ll i=0;i<sz;++i){
            for(ll j=q[i][0];j<=q[i][1];++j){
                ans[i]=(ans[i]*p[j])%mod;
            }
        }
        return ans;
    }
};