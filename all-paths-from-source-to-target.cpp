class Solution {
public:
    vector<vector<int>>res;
    int n;
    vector<bool>vis;
    void dfs(const vector<vector<int>>& g, int m, vector<int>v = {}) {
        if (m == n - 1) {
            v.push_back(m);
            res.push_back(v);
            return;
        }
        vis[m] = true;
        v.push_back(m);
        for (const int& i : g[m])
            if (!vis[i])
                dfs(g, i, v);
        v.pop_back();
        vis[m] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        n = g.size();
        vis.resize(n);
        dfs(g, 0);
        return res;
    }
};