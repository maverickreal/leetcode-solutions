class Solution {
public:
    int maxProduct(vector<string>& v) {
        int sz = v.size(), res = 0;
        vector<vector<int>>hash(sz, vector<int>(26));
        for (int i = 0;i < sz;++i) {
            int szs = v[i].length();
            for (int j = 0;j < szs;++j)
                ++hash[i][v[i][j] - 'a'];
        }
        //cout<<"out";
        for (int i = 0;i < sz;++i) {
            for (int j = i + 1;j < sz;++j) {
                int k = 0, a = 0, b = 0;
                for (;k < 26;++k) {
                    if (hash[i][k] && hash[j][k])
                        break;
                    a += hash[i][k];
                    b += hash[j][k];
                }
                if (k == 26)
                    res = max(res, a * b);
            }
        }
        return res;
    }
};