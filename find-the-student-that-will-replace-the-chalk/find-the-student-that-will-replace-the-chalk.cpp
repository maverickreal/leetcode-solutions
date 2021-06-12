class Solution {
public:
    int chalkReplacer(vector<int>& v, int k) {
        int sz = v.size(), sum = 0;
        for (int i = 0;i < sz;++i) {
            if (v[i] > k)
                return i;
            k -= v[i];
            sum += v[i];
        }
        k %= sum;
        int i = 0;
        for (;i < sz;++i) {
            if (v[i] > k)
                break;
            k -= v[i];
        }
        return i;
    }
};