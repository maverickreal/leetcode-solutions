class Solution {
public:
    static bool func(const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& v) {
        int sz = v.size(), res = 0;
        sort(v.begin(), v.end(), func);
        for (int i = 1;i < sz;++i)
            if (v[i][0] != v[i - 1][0])
                res = max(res, v[i][0] - v[i - 1][0]);
        return res;
    }
};