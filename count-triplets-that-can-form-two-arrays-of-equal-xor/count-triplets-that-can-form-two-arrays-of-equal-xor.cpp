class Solution {
public:
    int countTriplets(vector<int>& v) {
        int sz = v.size(), res = 0, xo = 0;
        unordered_map<int, list<int>>ump;
        for (int i = 0;i < sz;++i) {
            xo ^= v[i];
            if (!xo)
                res += i;
            if (ump.find(xo) != ump.end()) {
                for (const int& j : ump[xo])
                    res += i - j-1;
            }
            ump[xo].push_back(i);
        }
        return res;
    }
};