class Solution{
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int maxSum(vector<vector<int>>&v) {
        ll m=v.size(), n=v[0].size();
        ll ans=0;
        for(ll i=0;i<m;++i){
            for(ll j=0;j<n;++j){
                if(j+2>=n || i+2>=m){
                    continue;
                }
                ll res=v[i][j]+v[i][j+1]+v[i][j+2]+v[i+1][j+1]+v[i+2][j]+v[i+2][j+1]+v[i+2][j+2];
                ans=max(ans, res);
            }
        }
        return ans;
    }
};