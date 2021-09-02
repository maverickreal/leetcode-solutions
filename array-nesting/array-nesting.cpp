class Solution {
public:
    int arrayNesting(vector<int>& v) {
        int n = v.size(), res = 0;
        for (int i = 0;i < n;++i) {
            if (v[i] == -1)
                continue;
            int ans = 0, in = v[i];
            while (in > -1 && in < n && v[in] != -1) {
                ++ans;
                int tmp = v[in];
                v[in] = -1;
                in = tmp;
            }
            res = max(res, ans);
        }
        return res;
    }
};