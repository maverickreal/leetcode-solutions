class Solution {
public:
    int sb,sw;
    vector<vector<int>>v;
    vector<int>dp;
    int func(int b = 0, int ht = 0) {
        //cout<<b<<' '<<ht<<'\n';
        if (b == sb)
            return 0;
        if (dp[b] == INT_MAX) {
            int len = 0, br = INT_MIN,cur=b;
            while (cur < sb && len + v[cur][0] <= sw) {
                br = max(br, v[cur][1]);
                len+=v[cur][0];
                dp[b] = min(dp[b], br + func(cur + 1, ht + br));
                ++cur;
            }
        }
        return dp[b];
    }
    int minHeightShelves(vector<vector<int>>& b, int shw) {
        v = move(b), sb = v.size();
        dp.resize(sb, INT_MAX);
        sw=move(shw);
        return func();
    }
};