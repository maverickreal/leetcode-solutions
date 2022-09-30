class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int numberOfPaths(int n, vector<vector<int>>&e) {
        vi(unordered_set<ll>)g(n+1);
        for(auto edge:e){
            g[min(edge[0], edge[1])].insert(max(edge[0], edge[1]));
        }
        ll ans=0;
        for(auto edge:e){
            for( ll nd:g[edge[0]]){
                if(g[edge[1]].find(nd)!=g[edge[1]].end()){
                    ++ans;
                }
            }
        }
        return ans;
    }
};