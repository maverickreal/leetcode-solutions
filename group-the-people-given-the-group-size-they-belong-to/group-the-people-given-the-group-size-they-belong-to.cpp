class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        int sz = v.size();
        vector<vector<int>>hash(1+*max_element(v.begin(), v.end())), res;
        for (int i = 0;i < sz;++i) {
            if (hash[v[i]].size() == v[i]) {
                res.push_back(hash[v[i]]);
                hash[v[i]].clear();
            }
            hash[v[i]].push_back(i);
        }
        for (const auto& it : hash)
            if (!it.empty())
                res.push_back(it);
        return res;
    }
};