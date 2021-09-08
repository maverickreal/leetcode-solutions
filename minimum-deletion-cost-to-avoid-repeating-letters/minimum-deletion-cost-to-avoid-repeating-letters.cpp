class Solution {
public:
    int minCost(string& s, vector<int>& v) {
        int sz = s.length(), res = 0;
        for (int i = 0;i < sz;++i) {
            int j = i + 1;
            for (;j < sz && s[j] == s[i];++j);
            --j;
            if (j == i)
                continue;
            int mx = -1, sum = 0;
            for (int k = i;k <= j;++k) {
                mx = max(mx, v[k]);
                sum += v[k];
            }
            res += sum - mx;
            i = j;
        }
        return res;
    }
};