class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    long long countSubarrays(vector<int>&v, int mn, int mx) {
        ll n=v.size(), mnPtr=-1, mxPtr=-1, pre=0, ans=0;
        for(ll i=0;i<n;++i){
            if(v[i]<mn || v[i]>mx){
                pre=i+1, mnPtr=-1, mxPtr=-1;
                continue;
            }
            if(v[i]==mn){
                mnPtr=i;
            }
            if(v[i]==mx){
                mxPtr=i;
            }
            ans+=max(0LL, min(mnPtr, mxPtr)-pre+1);
        }
        return ans;
    }
};