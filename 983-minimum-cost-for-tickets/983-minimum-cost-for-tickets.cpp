class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(ll))dp;
    ll func(const vi(int)&v, ll in, ll cur, const vi(int)&c){
        if(in>=n){
            return 0;
        }
        ll&ans=dp[in][cur];
        if(ans==-1){
            if(cur>=v[in]){
                ans=func(v, in+1, cur, c);
            }
            else{
                ans=min({c[0]+func(v, in+1, v[in], c), c[1]+func(v, in+1, v[in]+6, c), c[2]+func(v, in+1, v[in]+29, c)});
            }
        }
        return ans;
    }
    int mincostTickets(vector<int>&v, vector<int>&c) {
        n=v.size();
        dp.assign(400, vi(ll)(400, -1));
        return func(v, 0, 0, c);
    }
};