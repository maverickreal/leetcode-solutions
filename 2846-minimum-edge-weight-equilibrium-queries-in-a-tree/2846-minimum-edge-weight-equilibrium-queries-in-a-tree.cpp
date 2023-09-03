class Solution {
public:
    int n, ht;
    vector<vector<vector<int>>>g;
    vector<vector<int>>maps, st;
    vector<int>level, par;
    void dfs(int nd, int parent, int depth, vector<int>&map){
        level[nd] = depth;
        par[nd] = parent;
        maps[nd] = map;
        for(const auto&child : g[nd]){
            if(child[0]==parent){
                continue;
            }
            ++map[child[1]];
            dfs(child[0], nd, depth+1, map);
            --map[child[1]];
        }
    }
    void preCompute(){
        for(int nd=0; nd<n; ++nd){
            st[nd][0] = par[nd];
        }
        for(int j=1; j<ht; ++j){
            for(int nd=0; nd<n; ++nd){
                if(st[nd][j-1]>-1){
                    st[nd][j] = st[st[nd][j-1]][j-1];
                }
            }
        }
    }
    int getAns(int u, int v){
        int l=u, r=v;
        if(l==r){
            return 0;
        }
        if(level[u]<level[v]){
            u+=v; v=u-v; u-=v;
        }
        int difLen = level[u]-level[v];
        for(int i=31; i>-1; --i){
            if((difLen>>i)&1){
                u = st[u][i];
            }
        }
        for(int i=ht-1; i>-1; --i){
            if(st[u][i]!=st[v][i]){
                u = st[u][i];
                v = st[v][i];
            }
        }
        if(u!=v){
            u = par[u], v = par[v];
        }
        int sum = 0, mx = 0;
        for(int i=0; i<27; ++i){
            int wt = maps[l][i]+maps[r][i]-(2*maps[u][i]);
            sum+=wt;
            mx = max(mx, wt);
        }
        return sum-mx;
    }
    vector<int> minOperationsQueries(int N, vector<vector<int>>&e, vector<vector<int>>&q) {
        n = N; ht=15;
        g.resize(n); level.resize(n); par.resize(n, -1);
        maps.resize(n, vector<int>(27));
        for(const auto&edge : e){
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int>map(27);
        dfs(n/2, -1, 0, map);
        st.resize(n, vector<int>(ht, -1));
        preCompute();
        int m=q.size();
        vector<int>ans(m);
        for(int i=0; i<m; ++i){
            ans[i] = getAns(q[i][0], q[i][1]);
        }
        return ans;
    }
};