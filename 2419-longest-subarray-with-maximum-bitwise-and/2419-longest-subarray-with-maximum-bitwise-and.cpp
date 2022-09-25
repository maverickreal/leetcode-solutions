class Solution {
    typedef long long ll;
typedef pair<string, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int longestSubarray(vector<int>&v) {
        ll n=v.size(), ans=0, mx=*max_element(v.begin(), v.end());
        for(ll i=0;i<n;++i){
            if(v[i]<mx){
                continue;
            }
            ll j=i+1;
            for(;j<n && v[j]==v[j-1];++j);
            --j;
            ans=max(ans, j-i+1);
            i=j;
        }
        return ans;
    }
};