class Solution {
public:
    int totalHammingDistance(vector<int>& v) {
        int sz = v.size();
        long res = 0;
        for (int i = 0;i < 32;++i) {
            int z = 0, o = 0;
            for (int& j : v) {
                j & 1 ? ++o : ++z;
                j >>= 1;
            }
            res += z * o;
        }
        return res;
    }
};