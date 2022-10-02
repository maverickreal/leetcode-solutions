class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(ll)dp;
    vi(vi(ll))pref;
    ll func(const string&s, ll in){
        if(in>=n){
            return 0;
        }
        ll&ans=dp[in];
        if(ans==-1){
            ans=1;
            for(ll j=in;(2*j)-in+1<n;++j){
                if(pref[in][j]==pref[j+1][(2*j)-in+1]){
                    ans=max(ans, 1+func(s, j+1));
                }
            }
        }
        return ans;
    }
    int deleteString(const string&s) {
        n=s.size();
        dp.assign(n, -1), pref.assign(n, vi(ll)(n, -1));
        for(ll i=0;i<n;++i){
            pref[i][i]=s[i]-'a'+1;
            for(ll j=i+1, pPow=31;j<n;++j){
                pref[i][j] = (pref[i][j-1] + (s[j] - 'a' + 1) * pPow) % mod;
                pPow = (pPow * 31) % mod;
            }
        }
        return func(s, 0);
    }
}; // j+1 +j-i