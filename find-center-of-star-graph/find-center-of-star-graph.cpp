class Solution {
public:
    int findCenter(vector<vector<int>>& g) {
        unordered_set<int>ust;
        for (const auto& it : g) {
            for (const int& ti : it) {
                if (ust.find(ti) != ust.end())
                    return ti;
                ust.insert(ti);
            }
        }
        return g[0][0];
    }
};