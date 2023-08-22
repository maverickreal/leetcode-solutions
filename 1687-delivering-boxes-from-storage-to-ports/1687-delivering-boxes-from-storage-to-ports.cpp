class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int pc, int mb, int mw) {
        int n = boxes.size();
        vector<int>dp(n, INT_MAX);
        int cw=0, cb=0;
        for(int i=0, j=0; i<n; ++i){
            cw += boxes[i][1];
            cb += !(j<i && boxes[i-1][0]==boxes[i][0]);
            while(j<i && (cw>mw || i-j+1>mb || (j && dp[j]<=dp[j-1]))){
                cw-=boxes[j][1];
                cb-=boxes[j][0]!=boxes[j+1][0];
                ++j;
            }
            dp[i] = (j ? dp[j-1] : 0) + cb + 1;
            // cout<<cb<<' '<<cw<<' '<<dp[i]<<endl;
        }

        return dp.back();
    }
};