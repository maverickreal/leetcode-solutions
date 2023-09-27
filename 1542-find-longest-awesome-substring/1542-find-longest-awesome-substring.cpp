class Solution {
public:
    int longestAwesome(string&str) {
        int n=str.size(), bm=0, ans=1;
        vector<int>ump(1<<10, n);
        ump[0]=-1;
        for(int i=0; i<n; ++i){
            bm^=1<<(str[i]-'0');
            int res = i-ump[bm];
            for(int j=0; j<10; ++j){
                res = max(res, i-ump[bm^(1<<j)]);
            }
            ans=max(ans, res);
            ump[bm] = min(ump[bm], i);
        }
        return ans;
    }
};