class Solution {
typedef long long ll;
typedef pair<ll, bool> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>&re, vector<vector<int>>&be) {
        vi(vi(pi))g(n);
        for(auto edge:re){
            g[edge[0]].pb({edge[1], 0});
        }
        for(auto edge:be){
            g[edge[0]].pb({edge[1], 1});
        }
        vi(int)ans(n, -1);
        vi(vi(bool))vis(n, vi(bool)(2));
        list<vi(ll)>l={{0, 0, 0}, {0, 0, 1}};
        while(!l.empty()){
            vi(ll) v=l.front();
            l.pop_front();
            if(vis[v[0]][v[2]]){
                continue;
            }
            vis[v[0]][v[2]]=true;
            if(ans[v[0]]==-1 || ans[v[0]]>v[1]){
                ans[v[0]]=v[1];
            }
            for(const pi&child:g[v[0]]){
                if(child.second!=v[2] && !vis[child.first][child.second]){
                    l.pb({child.first, 1+v[1], child.second});
                }
            }
        }
        return ans;
    }
};