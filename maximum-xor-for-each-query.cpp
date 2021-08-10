class Solution {
public:
    vector<int> getMaximumXor(vector<int>& v, int mxb) {
        int sz = v.size(), xo = 0;
        vector<int>res(sz);
        for (const int& i : v)
            xo ^= i;
        //cout<<xo<<'\n';
        const int tmp = (1 << mxb) - 1;
//cout<<tmp<<'\n';
        for (int i = 0;i < sz;++i) {
            if (i)
                xo ^= v[sz - i];
            res[i] = xo ^ tmp;
            //cout<<xo<<' ';
        }
        return res;
    }
};

