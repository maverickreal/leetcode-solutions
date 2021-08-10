class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& v) {
        int sz = v.size();
        vector<bool>ind(n);
        vector<int>res;
        for (const auto& i : v)
            ind[i[1]] = true;
        for (int i = 0;i < n;++i)
            if (!ind[i])
                res.push_back(i);
        return res;
    }
};