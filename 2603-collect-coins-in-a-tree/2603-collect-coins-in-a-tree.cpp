class Solution {
public:
    unordered_map<int, unordered_set<int>>g;

    void trimNoValueLeaves(const vector<int>&val){
        queue<int>q;
        for(const auto&[k, v] : g){
            if(v.size()==1 && !val[k]){
                q.push(k);
            }
        }
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            if(!g[nd].empty()){
                int par = *begin(g[nd]);
                if(g[par].find(nd)!=g[par].end()){
                    g[par].erase(nd);
                }
                g[nd].erase(par);
                if(g[par].size()==1 && !val[par]){
                    q.push(par);
                }
            }
        }
    }
    void trimNotToVisitLeaves(){
        // for(const auto&[k, v] : g){
        //     cout<<k<<endl;
        //     for(const auto& nd : v){
        //         cout<<nd<<' ';
        //     }
        //     cout<<endl;
        // }
        // return;
        for(int i=0;i<2;++i){
            vector<int>tmp;
            for(const auto&[k, v] : g){
                if(v.size()==1){
                    tmp.push_back(k);
                }
            }
            for(int nd : tmp){
                if(!g[nd].empty()){
                    int par = *begin(g[nd]);
                    g[nd].erase(par);
                    if(g[par].find(nd)!=g[par].end()){
                        g[par].erase(nd);
                    }
                }
            }
        }
    }
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        for(const auto&edge : edges){
            g[edge[0]].insert(edge[1]), g[edge[1]].insert(edge[0]);
        }
        trimNoValueLeaves(coins) ; trimNotToVisitLeaves();
        int ans=0;
        for(const auto&[k, v] : g){
            ans+=v.size();
        }
        return ans;
    }
};