class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int maxCandies(vector<int>&keys, const vector<int>&c, const vector<vector<int>>&k, const vector<vector<int>>&g, vector<int>&v) {
        list<ll>l(begin(v), end(v));
        ll ans=0, n=k.size();
        vi(bool)vis(n, 0);
        while(!l.empty()){
            ll nd=l.front();
            l.pop_front();
            cout<<nd<<' ';
            if(keys[nd]){
                vis[nd]=2;
                ans+=c[nd];
                for(ll child:g[nd]){
                    l.pb(child);
                }
                for(ll key:k[nd]){
                    keys[key]=1;
                }
            }
            else if(vis[nd]!=-1 && !l.empty()){
                l.pb(nd);
                vis[nd]=-1;
            }
        }
        return ans;
    }
};