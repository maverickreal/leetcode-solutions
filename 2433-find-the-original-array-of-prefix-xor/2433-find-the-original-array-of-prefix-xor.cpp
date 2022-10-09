class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<int> findArray(vector<int>& pref) {
        ll n=pref.size();
        vi(int)ans(n);
        ans[0]=pref[0];
        for(ll i=1;i<n;++i){
            ans[i]=pref[i-1]^pref[i];
        }   
        return ans;
    }
};