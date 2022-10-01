class Solution {
public:
    int xorAllNums(vector<int>& alpha, vector<int>& beta) {
        int ans=0, n = alpha.size(), m = beta.size(), xoa = 0 , xob = 0;
        for (int i = 0 ; i < m ;i++){
            xob^=beta[i];
        }
        for (int i = 0 ; i < n ;++i){
            xoa^=alpha[i];
        }
        if ((n&1) && !(m&1)){
            ans = xob;
        }
        else if (!(n&1) && !(m&1)){
            ans = 0;
        }
        else if ((n&1) && (m&1)){
            ans = xoa ^ xob;
        }
        else if (!(n&1) && (m&1)){
            ans = xoa;
        }
        return ans;
    }
};