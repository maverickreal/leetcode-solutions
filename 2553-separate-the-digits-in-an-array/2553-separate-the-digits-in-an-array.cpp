class Solution {
public:
    vector<int> separateDigits(vector<int>&v) {
        vector<int>ans;
        for(const int&it:v){
            for(const char&ch:to_string(it)){
                ans.push_back(ch-'0');
            }
        }
        return ans;
    }
};