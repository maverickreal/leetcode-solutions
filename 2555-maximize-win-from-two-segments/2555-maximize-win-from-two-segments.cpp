class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9+7;
const char nl = '\n';

int maximizeWin(vector<int>&v, int k) {
    ll n=v.size(), ans=0;
    vi(ll)dp(n);
    for(ll i=0, j=0;i<n;++i){
        while(j<i && v[i]-v[j]>k){
            ++j;
        }
        dp[i]=max(i?dp[i-1]:0, i-j+1);
        ans=max(ans, i-j+1+(j?dp[j-1]:0));
    }
    return ans;
}
};