class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }
    unordered_map<int, int>dp;
    int func(int m) {
        if (dp.find(m) == dp.end()) {
            if (m < 3)
                dp[m] = (m != 1);
            else if (m & 1)
                dp[m] = 1 + func((3 * m) + 1);
            else
                dp[m] = 1 + func(m >> 1);
        }
        return dp[m];
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>>v;
        for (int i = lo;i <= hi;++i)
            v.push_back({ func(i),i });
        sort(v.begin(), v.end(), cmp);
        return v[k - 1].second;
    }
};