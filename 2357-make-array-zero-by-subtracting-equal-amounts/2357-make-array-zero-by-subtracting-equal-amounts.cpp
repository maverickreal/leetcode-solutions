class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>ust(nums.begin(), nums.end());
        int ans=ust.size();
        if(ust.find(0)!=ust.end()){
            --ans;
        }
        return ans;
    }
};