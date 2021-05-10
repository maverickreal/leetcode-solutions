class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
        int mxel = *max_element(v.begin(), v.end());
        vector<int>hashdp(mxel + 1);
        for (int& i : v)
            ++hashdp[i];
        hashdp[mxel] *= mxel;
        hashdp[mxel - 1] = max(hashdp[mxel], (mxel - 1) * hashdp[mxel - 1]);
        for (int i = mxel - 2;i > -1;--i)
            hashdp[i] = max(hashdp[i + 1], i * hashdp[i] + hashdp[i + 2]);
        //for (int& i : hashdp)
          //  cout << i << ' ';
        return hashdp.front();
    }
};