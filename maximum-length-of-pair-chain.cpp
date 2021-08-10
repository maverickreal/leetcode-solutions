class Solution {
    class comp {
    public:
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        }
    };
public:
    int findLongestChain(vector<vector<int>>& v) {
        int sz = v.size(), res = 1, j = 0;
        sort(v.begin(), v.end(), comp());
        for (int i = 1;i < sz;++i) {
            if (v[j][1] < v[i][0]) {
                ++res;
                j = i;
            }
        }
        return res;
    }
};