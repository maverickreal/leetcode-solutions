class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
unordered_map<ll, vi(ll)>g;
void func(vi(vi(int))&ans, ll nd){
    while(!g[nd].empty()){
        ll child=g[nd].back();
        g[nd].pop_back();
        func(ans, child);
        ans.pb({int(nd), int(child)});
    }
}
    vector<vector<int>> validArrangement(vector<vector<int>>&v) {
        unordered_map<ll,ll>in, out;
        for(const auto&it:v){
            g[it[0]].pb(it[1]);
            ++in[it[1]], ++out[it[0]];
        }
        ll start=begin(g)->first;
        for(const auto&it:out){
            ll nd=it.first;
            if(out[nd]==in[nd]+1){
                start=nd;
                break;
            }
        }
        //cout<<"start : "<<start<<nl;
        vi(vi(int))ans;
        func(ans, start);
        reverse(begin(ans), end(ans));
        return ans;
    }
};