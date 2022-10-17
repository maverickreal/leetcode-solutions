class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(vi(ll))dp, pre;
    ll func(const vi(string)&v, const string&s, ll i, ll j){
        if(j==s.size()){
            return 1;
        }
        if(i==v[0].size()){
            return 0;
        }
        ll&ans=dp[i][j];
        if(ans==-1){
            ans=(func(v, s, i+1, j)+(pre[i][s[j]-'a']*func(v, s, i+1, j+1)))%mod;
        }
        return ans;
    }
    int numWays(vector<string>&v, const string&s) {
        dp.assign(v[0].size(), vi(ll)(s.size(), -1));
        pre.assign(v[0].size(), vi(ll)(26, 0));
        for(const string&str:v){
            for(ll i=0;i<str.size();++i){
                pre[i][str[i]-'a']++;
            }
        }
        return func(v, s, 0, 0);
    }
};