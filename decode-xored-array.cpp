class Solution {
public:
    vector<int> decode(vector<int>& v, int n) {
        int sz = v.size();
        vector<int>res(sz + 1);
        res[0] = n;
        for (int i = 0;i < sz;++i) {
            res[i + 1] = n ^ v[i];
            n = res[i + 1];
        }
        return res;
    }
};