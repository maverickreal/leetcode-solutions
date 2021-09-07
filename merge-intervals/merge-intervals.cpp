class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int sz = v.size();
        sort(v.begin(), v.end(), cmp);
        vector<vector<int>>res = { v[0] };
        /* for (auto i : v)
            for (int j : i)
                cout << j << ' '; */
        for (int i = 1;i < sz;++i) {
            if (v[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], v[i][1]);
            else
                res.push_back(v[i]);
        }
        return res;
    }
};