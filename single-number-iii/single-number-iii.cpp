class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {
        long x = 0, bm = 0, bm0 = 0;
        for (const int& i : v)
            bm ^= i;
        bm0 = bm;
        bm &= -bm;
        for (const int& i : v)
            if (bm & i)
                x ^= i;
        int a = x, b = x ^ bm0;
        return { a,b };
    }
};