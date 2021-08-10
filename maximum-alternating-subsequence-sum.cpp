class Solution {
public:
#define ll long long
    int sz;
    unordered_map<int, ll>ev, od;
    ll func(vector<int>& v, int i = 0, bool fl = true) {
        if (i == sz)
            return 0;
        if (fl) {
            if (ev.find(i) == ev.end())
                ev[i] = max(v[i] + func(v, i + 1, false), func(v, i + 1, fl));
            return ev[i];
        }
        if (od.find(i) == od.end())
            od[i] = max(func(v, i + 1, true) - v[i], func(v, i + 1, fl));
        return od[i];
    }
    long long maxAlternatingSum(vector<int>& v) {
        sz = v.size();
        return func(v);
    }
};