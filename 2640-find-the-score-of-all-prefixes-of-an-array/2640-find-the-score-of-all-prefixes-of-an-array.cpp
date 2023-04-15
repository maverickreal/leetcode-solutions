class Solution{
    typedef long long ll;
public:
    vector<ll> findPrefixScore(const vector<int>&v){
        ll n=v.size();
        vector<ll>ans(n), pref(n); // Convers
        pref[0]=ans[0]=2*v[0];
        for(ll i=1, mx=v[0]; i<n; ++i){
            mx=max(mx, ll(v[i])); // max so far
            pref[i]=v[i]+mx;
            ans[i]=ans[i-1]+pref[i]; // sum of Convers, i.e., the cur score
        }
        return ans;
    }
};