class Solution {
typedef long long ll;
#define vi(x) vector<x>
public:
    int oddEvenJumps(vector<int>&v) {
        ll ans=1, n=v.size();
        map<ll,ll>mp={{v[n-1], n-1}};
        map<ll, ll, greater<ll>>revMp={{v[n-1], n-1}};
        vi(vi(bool))dp(n, vi(bool)(2));
        dp[n-1]={1, 1};
        for(ll i=n-2;i>-1;--i){
            const auto&it=mp.lower_bound(v[i]);
            dp[i][0]=it!=mp.end() && dp[it->second][1];
            const auto&ti=revMp.lower_bound(v[i]);
            dp[i][1]=ti!=revMp.end() && dp[ti->second][0];
            ans+=dp[i][0];
            mp[v[i]]=revMp[v[i]]=i;
        }
        return ans;
    }
};