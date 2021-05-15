class Solution {
public:
    string toHex(int num) {
        string res = "";
        vector<char>v = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
        if (num > -1 && num < 16) {
            res.push_back(v[num]);
            return res;
        }
        vector<bool> n(32);
        int tmp = abs(num);
        for (int i = 0;i < 32;++i) {
            if (num > -1)
                n[i] = tmp & 1;
            else
                n[i] = !(tmp & 1);
            tmp >>= 1;
        }
        if (num < 0) {
            int rem = 1;
            int i = -1;
            while (rem && (++i < 32)) {
                tmp = n[i];
                n[i] = (tmp + rem) % 2;
                rem = (tmp + rem) >> 1;
            }
        }
        for (int i = 0;i < 32;i += 4) {
            tmp = 0;
            for (int j = 0;j < 4;++j)
                tmp += (1 << j) * n[i + j];
            res.push_back(v[tmp]);
        }
        while (!res.empty() && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};