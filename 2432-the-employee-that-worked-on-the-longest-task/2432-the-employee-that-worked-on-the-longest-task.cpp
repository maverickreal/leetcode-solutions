class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int hardestWorker(int n, vector<vector<int>>&v) {
        ll ans=v[0][0], pre=v[0][1];
        for(ll i=1;i<v.size();++i){
            ll res=v[i][1]-v[i-1][1];
            if(res>pre){
                pre=res, ans=v[i][0];
            }
            else if(res==pre){
                ans=min(ans, ll(v[i][0]));
            }
        }
        return ans;
    }
};