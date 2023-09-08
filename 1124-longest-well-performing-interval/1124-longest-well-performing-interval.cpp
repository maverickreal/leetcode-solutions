class Solution {
public:
    int longestWPI(vector<int>&v) {
        int ans = 0;
        for(int i=0; i<v.size(); ++i){
            int tiring=0;
            for(int j=i; j<v.size(); ++j){
                tiring+=v[j]>8;
                if(tiring>j-i+1-tiring){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};