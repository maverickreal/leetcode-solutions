class Solution {
public:
    int n;
    unordered_map<int, vector<int>>dp;
    int func(const vector<int>&c, const vector<int>&t, int ind, int rem){
        if(ind==n){
            return (rem>-1 ? 0 : INT_MAX);
        }
        if(dp[rem].empty()){
            dp[rem].resize(n, -1);
        }
        if(dp[rem][ind]!=-1){
            return dp[rem][ind];
        }
        int dont = func(c, t, ind+1, rem-1);
        int take = func(c, t, ind+1, rem+t[ind]);
        if(take<INT_MAX){
            take+=c[ind];
        }
        return dp[rem][ind]=min(take, dont);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        return func(cost, time, 0, 0);
    }
};