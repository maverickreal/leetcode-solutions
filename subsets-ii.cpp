class Solution {
public:
#define vi vector<int>
    int sz;
    vector<vi>res;
    void func(const vector<int>& v, int in, vi cur, bool prev) {
        if (in == sz) {
            res.push_back(cur);
            return;
        }
        func(v, in + 1, cur, false);
        if (!in || v[in] != v[in - 1] || prev) {
            cur.push_back(v[in++]);
            func(v, in, cur, true);
        }
    }
    vector<vi> subsetsWithDup(vi& v) {
        sz = v.size();
        sort(v.begin(), v.end());
        func(v, 0, {}, true);
        return res;
    }
};