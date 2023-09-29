class Solution {
public:
    int m, n;
    int dfs(vector<vector<int>>&v, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || !v[i][j]){
            return 0;
        }
        v[i][j]=0;
        if(i==m-1 && j==n-1){
            return 1;
        }
        return dfs(v, i, j+1) || dfs(v, i+1, j);
    }
    bool isPossibleToCutPath(vector<vector<int>>&v) {
        m=v.size(), n=v[0].size();
        if(!dfs(v, 0, 0)){
            return 1;
        }
        v[0][0]=v[m-1][n-1]=1;
        return !dfs(v, 0, 0);
    }
};