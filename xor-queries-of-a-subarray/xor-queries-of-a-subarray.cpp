class Solution {
public:
    vector<int> xorQueries(vector<int>& v, vector<vector<int>>& q) {
        int szv = v.size(), szq = q.size();
        vector<int>res(szq);
        for (int i = 1;i < szv;++i)
            v[i] ^= v[i - 1];
        for (int i = 0;i < szq;++i) {
            int a = q[i][0], b = q[i][1];
            res[i] = v[b];
            if (a)
                res[i] ^= v[a - 1];
        }
        return res;
    }
};