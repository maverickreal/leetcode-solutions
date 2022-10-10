class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll n;
    ll func(const vi(int)&v, ll in, const int&tar, ll rem){
        if(rem<0){
            return 0;
        }
        // if(rem==0){
        //     return (in==tar);
        // }
        ll&ans=dp[in][rem];
        if(ans==-1){
            ans=(in==tar);
            for(ll i=0;i<n;++i){
                if(i!=in){
                    ans=(ans+func(v, i, tar, rem-abs(v[i]-v[in])))%mod;
                }
            }
        }
        //cout<<in<<' '<<rem<<' '<<ans<<nl;
        return ans;
    }
    int countRoutes(vector<int>&v, int beg, int end, int k) {
        n=v.size();
        dp.assign(n, vi(ll)(k+1, -1));
        return func(v, beg, end, k);
    }
};