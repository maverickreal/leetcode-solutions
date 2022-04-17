class Solution {
public:
    unordered_set<int>ust;
    vector<vector<int>> res;
    int n;
    void func(const vector<vector<int>>& g, int i, vector<int>v) {
        if (i == n - 1)
            res.push_back(v);
        ust.insert(i);
        for (const int& it : g[i]) {
            if (ust.find(it) == ust.end()) {
                v.push_back(it);
                func(g, it, v);
                v.pop_back();
            }
        }
        ust.erase(i);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        func(graph, 0, {0});
        return res;
    }
};