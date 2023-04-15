class Solution {
public:
    int getWidth(const vector<vector<int>>&v, int col){
        int ans=0;
        for(int row=0; row<v.size(); ++row){
            ans=max(ans, (int)to_string(v[row][col]).size());
        }
        return ans;
    }

    vector<int> findColumnWidth(const vector<vector<int>>&v) {
        int m=v.size(), n=v[0].size();
        vector<int>ans(n);
        for(int col=0; col<n; ++col){
            ans[col]=getWidth(v, col);
        }
        return ans;
    }
};