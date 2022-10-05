class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)dp;
    bool func(ll n){
        if(n==0){
            return false;
        }
        ll&ans=dp[n];
        if(ans==-1){
            ans=0;
            for(ll i=1;i*i<=n && !ans;++i){
                if(!func(n-i*i)){
                    ans=1;
                }
            }
        }
        return ans;
    }
    bool winnerSquareGame(int n) {
        dp.assign(n+1, -1);
        return func(n);
    }
};