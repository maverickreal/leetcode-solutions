class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>&e) {
        vi(vi(ll))g(n);
        for(auto edge:e){
            g[edge[0]-1].pb(edge[1]-1);
            g[edge[1]-1].pb(edge[0]-1);
        }
        vi(int)res(n);
        for(ll i=0;i<n;++i){
            bitset<5>bs(0);
            for(ll j:g[i]){
                bs[res[j]]=1;
            }
            for(ll c=1;c<5;++c){
                if(!bs[c]){
                    res[i]=c;
                    break;
                }
            }
        }
        return res;
    }
};