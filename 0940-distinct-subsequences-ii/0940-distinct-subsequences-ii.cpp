class Solution {
public:
    const int mod = 1e9+7;
    int n;
    vector<vector<int>>dp;
    int func(const string&str, int ind, char ch){
        if(ind==n){
            return 0;
        }
        if(dp[ind][ch-'a']!=-1){
            return dp[ind][ch-'a'];
        }
        int ans=0;
        if(str[ind]!=ch){
            ans = func(str, ind+1, ch);
        }
        else{
            ans = 1;
            for(char nxt = 'a'; nxt<='z'; ++nxt){
                ans = (ans + func(str, ind+1, nxt))%mod;
            }
        }
        return dp[ind][ch-'a'] = ans;
    }
    int distinctSubseqII(string&str) {
        n=str.size();
        dp.resize(n, vector<int>(26, -1));
        int ans=0;
        for(char ch='a'; ch<='z'; ++ch){
            ans=(ans + func(str, 0, ch))%mod;
        }
        return ans;
    }
};
