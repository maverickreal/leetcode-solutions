class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        int sz = v.size(), i = 0, j = sz - 1, k = -1;
        vector<int>res(sz);
        while (i <= j) {
            ++k;
            if (abs(v[i]) > abs(v[j]))
                res[k] = v[i] * v[i++];
            else
                res[k] = v[j] * v[j--];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};