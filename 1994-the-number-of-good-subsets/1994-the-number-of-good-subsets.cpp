class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
ll modExp(ll x, ll y, ll m){
    ll res = 1;
    x%=m;
    if (!x){
        return 0;  
    }
    while (y > 0){
        if (y & 1){
            res = (res*x) % m;
        }
        y>>=1;
        x = (x*x) % m;
    }
    return res;
}
    const vi(vi(ll))ump={{1, 0}, {2, 4}, {3, 8}, {5,32}, {6, 12}, {7, 128}, {10, 36}, {11, 2048}, {13, 1LL<<13}, {14, 132}, {15, 40}, {17, 1LL<<17}, {19, 1LL<<19}, {21, 136}, {22, 2052}, {23, 1LL<<23}, {26, 4+(1LL<<13)}, {29, 1LL<<29}, {30, 44}};
    vi(ll)v;
    unordered_map<ll,vi(ll)>dp;
    ll func(ll in, ll bm){
        if(in==ump.size()){
            return 1;
        }
        if(dp[bm].empty()){
            dp[bm].assign(ump.size(), -1);
        }
        ll&ans=dp[bm][in];
        if(ans==-1){
            ans=func(in+1, bm);
            if(!(bm&ump[in][1])){
                ans=(ans+(v[ump[in][0]]*func(in+1, bm|ump[in][1]))%mod)%mod;
            }
        }
        return ans;
    }
    int numberOfGoodSubsets(vector<int>&arr) {
        v.assign(31, 0);
        for(ll it:arr){
            ++v[it];
        }
        ll ans=func(1, 0)-1;
        ans=(ans*modExp(2, v[1], mod))%mod;
        return ans;
    }
};