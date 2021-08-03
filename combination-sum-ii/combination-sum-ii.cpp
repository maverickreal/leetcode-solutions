class Solution {
public:
#define vi vector<int>
    vector<vi>res;
    // unordered_set<string>ust;
    void func(const vi& v, int in, int tar, vi cur) {
        if (!tar) {
            res.push_back(cur);
            return;
        }
        for (int i = in;i < v.size();++i) {
            if (tar - v[i] < 0)
                break;
            if (i > in && v[i] == v[i - 1])
                continue;
            cur.push_back(v[i]);
            func(v, i + 1, tar - v[i], cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int tar) {
        sort(v.begin(), v.end());
        func(v, 0, tar, {});
        return res;
    }
};