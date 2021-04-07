class Solution {
public:
    bool divisorGame(int n) {
    vector<bool>v(n + 1);
    v[2] = true;
    for (int i = 3;i <= n;++i) {
        for (int j = 1;j <= i >> 1;++j) {
            if (!(i % j || v[i - j])) {
                v[i] = true;
                break;
            }
        }
    }
    //for (bool b : v)
      //  cout << b << ' ';
    return v.back();
}
};