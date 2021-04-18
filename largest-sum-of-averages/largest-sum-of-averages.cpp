class Solution {
public:
    vector<int>v;
vector<vector<double>>memo;
int sz, k;
vector<double>pre;
double func(int j, /*double res = 0,*/ int i = 0) {
    //cout << j << ' ' /*<< res << ' ' */ << i << '\n';
    /* if (i == sz || j > sz - i  || !j)
        return res; */
    if (j == 1)
        return  (double)(pre.back() - pre[i - 1]) / (sz - i);
    if (j == sz - i)
        return (double)(pre.back() -(i ? pre[i - 1] : 0));
    if (memo[j][i] == -1) {
        for (int cnt = 1, I = i + 1;I <= sz - j + 1;++I, ++cnt)
            memo[j][i] = max(memo[j][i], (double)(pre[i + cnt - 1] - (i ? pre[i - 1] : 0)) / cnt + func(j - 1, cnt + i));
    }
    return memo[j][i];
}
double largestSumOfAverages(vector<int>& V, int K) {
    if (V.size() == 1)
        return (double)V[0];
    if (K == 1)
        return (double)accumulate(V.begin(), V.end(), 0) / V.size();
    v = move(V), k = K, sz = v.size();
    memo.resize(k + 1, vector<double>(sz, -1));
    pre.resize(sz);
    pre.front() = v.front();
    for (int i = 1;i < sz;++i)
        pre[i] = pre[i - 1] + v[i];
    return func(k);
}
};