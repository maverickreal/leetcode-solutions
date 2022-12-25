class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
const vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
ll n;
vi(vi(ll))dp;
ll func(const vi(int)&v, ll in, ll sum, const int&k){
    if(sum>=k){
        return 0;
    }
    if(in==n){
        return 1;
    }
    ll&ans=dp[in][sum];
    if(ans==-1){
        ans=(func(v, in+1, sum+v[in], k)+func(v, in+1, sum, k))%mod;
    }
    return ans;
}
    int countPartitions(vector<int>&v, int k) {
        n=v.size();
        if(accumulate(begin(v), end(v), 0LL)<2*k){
            return 0;
        }
        dp.resize(n, vi(ll)(k+1, -1));
        ll tot=1;
        for(ll i=0;i<n;++i){
            tot=(tot*2)%mod;
        }
        return (tot-(2LL*func(v, 0, 0, k))+mod)%mod;
    }
};