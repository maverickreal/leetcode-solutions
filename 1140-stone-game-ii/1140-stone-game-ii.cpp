class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(pi))dp;
    pi func(const vi(int)&v, ll in, ll m){
        if(in>=n){
            return {0, 0};
        }
        pi&ans=dp[in][m];
        if(ans==pi({-1, -1})){
            ans={0, 0};
            for(ll i=1, cur=0;i<=min(n-in, 2*m);++i){
                pi rec=func(v, in+i, max(m, i));
                if(cur+v[in+i-1]+rec.second>ans.first){
                    ans.first=cur+v[in+i-1]+rec.second, ans.second=rec.first;
                }
                cur+=v[in+i-1];
            }
        }
        return ans;
    }
    int stoneGameII(vector<int>&v) {
        n=v.size();
        dp.assign(n+1, vi(pi)(n+1, {-1, -1}));
        return func(v, 0, 1).first;
    }
};