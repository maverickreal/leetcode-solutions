class Solution {
public:
    int n;
    vector<unordered_set<int>>g;
    void trimNoCoinsLeaves(const vector<int>&coins){
        list<int>l;
        for(int nd=0; nd<n; ++nd){
            if(!coins[nd]){
                l.push_back(nd);
            }
        }
        while(!l.empty()){
            int nd = l.front();
            l.pop_front();
            if(g[nd].size()!=1){
                continue;
            }
            int child = *begin(g[nd]);
            g[nd].erase(child);
            if(g[child].find(nd)!=g[child].end()){
                g[child].erase(nd);
            }
            if(!coins[child] && g[child].size()==1){
                l.push_back(child);
            }
        }
    }
    void trim2levels(){
        for(int i=0; i<2; ++i){
            vector<int>leaves;
            for(int nd=0; nd<n; ++nd){
                if(g[nd].size()==1){
                    leaves.push_back(nd);
                }
            }
            for(int leaf : leaves){
                if(!g[leaf].empty()){
                    int par=*begin(g[leaf]);
                    g[leaf].erase(par);
                    if(g[par].find(leaf)!=g[par].end()){
                        g[par].erase(leaf);
                    }
                }
            }
        }
    }
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        n = edges.size()+1;
        g.resize(n);
        for(const auto&edge : edges){
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        trimNoCoinsLeaves(coins);
        trim2levels();
        int ans=0;
        for(const auto&ust : g){
            ans+=ust.size();
        }
        return ans;
    }
};