class Solution {
typedef long long ll;
typedef long double ld;
typedef pair<string, ld> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    unordered_map<string, vi(pi)>g;
    ld func(const string&a, const string&b){
        list<pi>l={{a, 1}};
        unordered_set<string>vis;
        while(!l.empty()){
            auto it=l.front();
            if(g.find(it.first)==g.end()){
                return -1;
            }
            if(it.first==b){
                return it.second;
            }
            l.pop_front();
            if(vis.find(it.first)!=vis.end()){
                continue;
            }
            vis.insert(it.first);
            for(auto child:g[it.first]){
                if(vis.find(child.first)==vis.end()){
                    l.pb({child.first, child.second*it.second});
                }
            }
        }
        return ld(-1);
    }
    vector<double> calcEquation(vector<vector<string>>&eq, vector<double>&vals, vector<vector<string>>&qs) {
        ll n=vals.size();
        for(ll i=0;i<n;++i){
            g[eq[i][0]].pb({eq[i][1], vals[i]});
            g[eq[i][1]].pb({eq[i][0], ld(1)/vals[i]});
        }
        vi(double)ans;
        for(auto q:qs){
            ans.pb(func(q[0], q[1]));
        }
        return ans;
    }
};