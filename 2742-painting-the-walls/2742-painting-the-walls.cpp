class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int func(const vector<int>&c, const vector<int>&t, int ind, int rem){
        if(rem<1){
            return 0;
        }
        if(ind==n){
            return INT_MAX;
        }
        if(dp[rem][ind]!=-1){
            return dp[rem][ind];
        }
        int dont = func(c, t, ind+1, rem);
        int take = func(c, t, ind+1, rem-1-t[ind]);
        if(take<INT_MAX){
            take+=c[ind];
        }
        return dp[rem][ind]=min(take, dont);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return func(cost, time, 0, n);
    }
};