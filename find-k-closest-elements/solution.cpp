class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        int sz = v.size();
        if (sz == k)
            return v;
        if (x > v.back())
            return vector<int>(v.begin() + sz - k, v.end());
        if (x < v.front())
            return vector<int>(v.begin(), v.begin() + k);
        int i, j = lower_bound(v.begin(), v.end(), x) - v.begin();
        list<int>res;
        if (v[j] == x) {
            res.push_front(v[j]);
            i = ++j - 2;
        }
        else
            i = j - 1;
        while (res.size() < k) {
            //cout<<i<<' '<<j<<'\n';
            if (i == -1) {
                res.push_back(v[j++]);
                continue;
            }
            if (j == sz) {
                res.push_front(v[i--]);
                continue;
            }
            int dif = abs(v[i] - x) - abs(v[j] - x);
            if (dif < 0 || (!dif && v[i] < v[j]))
                res.push_front(v[i--]);
            else if (dif > 0 || (!dif && v[j] < v[i]))
                res.push_back(v[j++]);
        }
        return vector<int>(res.begin(), res.end());
    }
};
