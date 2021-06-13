class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& mat, vector<int>& tar) {
        vector<int>tri(3);
        for (const vector<int>& v : mat) {
            if (v == tar) return true;
            if (v[0] > tar[0] || v[1] > tar[1] || v[2] > tar[2])
                continue;
            for (int i = 0;i < 3;++i)
                tri[i] = max(tri[i], v[i]);
        }
        return tri == tar;
    }
};