class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty())
            return m*n;
        int f=INT_MAX,s=f;
        for(auto&i:ops)
            f=min(f,i[0]),s=min(s,i[1]);
        return f*s;
    }
};