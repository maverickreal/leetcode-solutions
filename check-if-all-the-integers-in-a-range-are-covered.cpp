class Solution {
public:
    bool isCovered(vector<vector<int>>& v, int l, int r) {
        vector<bool>hash(r + 1);
        int sz = v.size();
        for (int i = 0;i < sz;++i) {
            if (v[i][0] > r || v[i][1] < l)
                continue;
            int s = max(v[i][0], l), e = min(v[i][1], r);
            for (int j = s;j <= e;++j)
                hash[j] = true;
        }
        for (int i = l;i <= r;++i)
            if (!hash[i])
                return false;
        return true;
    }
};