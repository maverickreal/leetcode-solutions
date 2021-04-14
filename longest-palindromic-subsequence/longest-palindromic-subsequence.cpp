class Solution {
public:
    int longestPalindromeSubseq(string&s) {
        int sz=s.length(),res=1;
        vector<vector<int>>dp(sz+1,vector<int>(sz+1));
        for(int i=1;i<=sz;++i){
            for(int r=1,c=i;r<=sz,c<=sz;++r,++c){
                if(r==c){
                    dp[r][c]=1;
                    continue;
                }
                if(s[r-1]==s[c-1])
                    dp[r][c]=2+dp[r+1][c-1];
                dp[r][c]=max(dp[r][c],max(dp[r+1][c],dp[r][c-1]));
                res=max(res,dp[r][c]);
            }
        }
        return res;
    }
};