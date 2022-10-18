class Solution {
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))dp;
    ll func(const string&s, ll i, ll j){
        if(i>=j){
            return 0;
        }
        ll&ans=dp[i][j];
        if(ans==-1){
            if(s[i]==s[j]){
                ans=func(s, i+1, j-1);
            }
            else{
                ans=1+min(func(s, i+1, j), func(s, i, j-1));
            }
        }
        return ans;
    }
    int minInsertions(const string&s) {
        dp.assign(s.size(), vi(ll)(s.size(), -1));
        return func(s, 0, s.size()-1);
    }
};