class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];

    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int sz = v.size();
        sort(v.begin(), v.end(), cmp);
        int res = 0, pre = 0;
        for (int i = 1;i < sz;++i) {
            if (v[i][0] < v[pre][1])
                ++res;
            else
                pre = i;
        }
        return res;
    }
};