class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
const ll mod = 1e9 + 7;

ll sz;

vi(vi(ll))dp;

ll func(const vi(vi(int))&v, ll in, ll rem){
    if(rem<0){
        return 0;
    }
    if(in==sz){
        return (rem==0);
    }
    ll&ans=dp[in][rem];
    if(ans==-1){
        ans=0;
        for(ll i=0;i<=v[in][0];++i){
            ans=(ans+func(v, in+1, rem-(i*v[in][1])))%mod;
        }
    }
    return ans;
}

int waysToReachTarget(int tar, vector<vector<int>>&v) {
    sz=v.size();
    dp.assign(sz+1, vi(ll)(tar+2, -1));
    return func(v, 0, tar);
}
};