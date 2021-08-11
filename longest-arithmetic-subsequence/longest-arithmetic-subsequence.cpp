class Solution {
public:
    int longestArithSeqLength(vector<int>& v) {
        int sz = v.size();
        if (sz < 3)
            return sz;
        int res = 2;
        vector<unordered_map<int, int>>ump(sz);
        for (int i = 0;i < sz;++i) {
            for (int j = i + 1;j < sz;++j) {
                int dif = v[j] - v[i];
                if (ump[i].find(dif) != ump[i].end())
                    ump[j][dif] = ump[i][dif] + 1;
                else
                    ump[j][dif] = max(ump[j][dif], 2);
                res = max(res, ump[j][dif]);
            }
        }
        return res;
    }
};