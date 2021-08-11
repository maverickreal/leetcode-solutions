class Solution {
public:
    static bool cmp(const int& i, const int& j) {
        return abs(i) < abs(j);
    }
    bool canReorderDoubled(vector<int>& v) {
        unordered_map<int, int>ump;
        for (int& i : v)
            ++ump[i];
        sort(v.begin(), v.end(), cmp);
        for (int& i : v) {
            if (ump.find(i) == ump.end())
                continue;
            if (ump.find(i * 2) == ump.end())
                return false;
            --ump[i * 2];
            if (!ump[i * 2])
                ump.erase(i * 2);
            --ump[i];
            if (!ump[i])
                ump.erase(i);
        }
        return true;
    }
};