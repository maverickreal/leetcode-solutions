class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(vi(ll)))dp;
    ll func(const vi(int)&v, ll i, ll j, ll pre){
        if(i>j){
            return 0;
        }
        ll&ans=dp[i][j][pre];
        if(ans==-1){
            ll oi=i;
            ++pre;
            while(i+1<=j && v[i+1]==v[oi]){
                ++i, ++pre;
            }
            ans=pre*pre+func(v, i+1, j, 0);
            for(ll k=i+1;k<=j;++k){
                if(v[k]==v[oi]){
                    ans=max(ans, func(v, i+1, k-1, 0)+func(v, k, j, pre));
                }
            }
        }
        return ans;
    }
    int removeBoxes(vector<int>&v) {
        n=v.size();
        dp.resize(n, vi(vi(ll))(n, vi(ll)(n+1, -1)));
        return func(v, 0, n-1, 0);
    }
};