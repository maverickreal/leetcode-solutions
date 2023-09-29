class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int ports, int mxb, int mxw) {
        int n=boxes.size();
        vector<int>dp(n, INT_MAX);
        int i=0, j=0, cw=0, cb=0;
        for(; j<n; ++j){
            cw+=boxes[j][1]; cb+=j==i || boxes[j][0]!=boxes[j-1][0];
            while(i<j && (cw>mxw || j-i+1>mxb || (i && dp[i]<=dp[i-1]))){
               cw-=boxes[i][1]; cb-=boxes[i][0]!=boxes[i+1][0]; ++i;
            }
            dp[j]=(i?dp[i-1]:0) + cb + 1;
        }
        return dp[n-1];
    }
};