class Solution {
public:
    int singleNumber(vector<int>& v) {
        sort(v.begin(), v.end());
        int sz = v.size();
        for (int i = 0;i < sz - 2;i += 3)
            if (v[i] != v[i + 1])
                return v[i];
        return v.back();
    }
};