class Solution {
public:
    typedef long long ll;
    ll maxArrayValue(vector<int>&v) {
        ll n =v.size(), ans = 0;
        for(ll i=n-1; i>-1; --i){
            ll sum = v[i];
            while(i && v[i-1]<=sum){
                sum+=v[--i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};