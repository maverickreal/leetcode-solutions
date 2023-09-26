class Solution {
public:
    int maximizeWin(vector<int>&pos, int k) {
        int n=pos.size(), ans=0;
        vector<int>dp(n);
        for(int i=0, j=0; i<n; ++i){
            while(j<i && pos[i]-pos[j]>k){
                ++j;
            }
            dp[i] = max(i?dp[i-1]:0, i-j+1);
            ans=max(ans, i-j+1+(j?dp[j-1]:0));
        }
        return ans;
    }
};