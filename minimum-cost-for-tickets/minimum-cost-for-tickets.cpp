class Solution {
public:
    int mincostTickets(vector<int> d, vector<int> c) {
        int sz = d.size();
        vector<int>dp(d.back() + 1);
        for (int i = 0;i < sz - 1;++i)
            for (int j = d[i] + 1;j < d[i + 1];++j)
                dp[j] = -d[i];
        dp[d[0]] = c[0];
        //for (int& i : dp)
          //  cout << i << ' ';
        for (int i = 1;i < sz;++i) {
            int day = d[i];
            int od = c[0] + (dp[day - 1] < 0 ? dp[-dp[day - 1]] : dp[day - 1]);
            int ow = c[1];
            if (day > 7) {
                int mn = INT_MAX;
                for (int j = day - 7;j < day;++j)
                    mn = min(mn, dp[j] < 0 ? dp[-dp[j]] : dp[j]);
                ow += mn;
            }
            int om = c[2];
            if (day > 30) {
                int mn = INT_MAX;
                for (int j = day - 30;j < day;++j)
                    mn = min(mn, dp[j] < 0 ? dp[-dp[j]] : dp[j]);
                om += mn;
            }
            dp[day] = min(min(od, ow), om);
        }
        /* cout << "\nhere\n";
        for (int& i : dp)
            cout << i << ' '; */
        return dp.back();
    }
};