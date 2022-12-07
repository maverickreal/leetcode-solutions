class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
unordered_map<string, vi(string)>g;
vi(string)ans;
void func(const string&nd){
    while(!g[nd].empty()){
        string child=g[nd].back();
        g[nd].pop_back();
        func(child);
    }
    ans.pb(nd);
}
vector<string> findItinerary(vector<vector<string>>&v) {
    for(const auto&it:v){
        g[it[0]].pb(it[1]);
    }
    for(auto&it:g){
        sort(rbegin(it.second), rend(it.second));
    }
    func("JFK");
    reverse(begin(ans), end(ans));
    return ans;
}
};