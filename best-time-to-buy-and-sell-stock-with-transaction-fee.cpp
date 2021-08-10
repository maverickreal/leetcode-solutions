class Solution {
public:
    int maxProfit(vector<int>& v, int f) {
        int b = -v[0], s = 0, sz = v.size();
        for (int i = 1;i < sz;++i) {
            int tb = s - v[i], ts = b + v[i] - f;
            s = max(s, ts), b = max(b, tb);
        }
        return s;
    }
};