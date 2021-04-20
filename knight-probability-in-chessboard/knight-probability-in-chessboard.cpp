class Solution {
public:
    int n;
unordered_map<string, double>ump;
double func(int r, int c, int k) {
    //cout << r << ' ' << c << ' ' << k << '\n';
    if (r < 0 || r >= n || c >= n || c < 0)
        return 0;
    if (!k)
        return 1;
    string s = to_string(r) + "." + to_string(c) + "." + to_string(k--);
    if (ump.find(s) == ump.end())
        ump[s] = (func(r - 2, c - 1, k) + func(r - 2, c + 1, k) + func(r + 2, c - 1, k) + func(r + 2, c + 1, k) + func(r - 1, c - 2, k) + func(r - 1, c + 2, k) + func(r + 1, c - 2, k) + func(r + 1, c + 2, k)) / 8;
    return ump[s];
}
double knightProbability(int N, int k, int r, int c) {
    n = move(N);
    return func(r, c, k);
}
};