class Solution {
    vector<vector<int>>memo;
    vector<int>sum, * v;
    int sz;
    int func(int i, int j) {
        //cout << i << ' ' << j << '\n';
        if (j == i + 1) {
            //cout << "ex 1\n";
            return max(v->at(j), v->at(i));
        }
        if (memo[i][j] == -1)
            memo[i][j] = max(sum[j] - sum[i] - func(i + 1, j), sum[j - 1] - (i ? sum[i - 1] : 0) - func(i, j - 1));
        //cout << "ex 2\n";
        return memo[i][j];
    }
public:
    int stoneGameVII(vector<int>& V) {
        v = &V;
        sz = V.size();
        if (sz == 1)
            return V[0];
        if (sz == 2)
            return max(V[0], V[1]);
        memo.resize(sz, vector<int>(sz, -1));
        sum.resize(sz);
        sum[0] = V[0];
        for (int i = 1;i < sz;++i)
            sum[i] = sum[i - 1] + V[i];
        /* for (int& i : sum)
            cout << i << ' ';
        cout << '\n';
        for (int i = 0;i < sz;++i) {
            for (int j = 0;j < sz;++j)
                cout << memo[i][j] << ' ';
            cout << '\n';
        } */
        return max(sum[sz - 1] - V[0] - func(1, sz - 1), sum[sz - 2] - func(0, sz - 2));
    }
};