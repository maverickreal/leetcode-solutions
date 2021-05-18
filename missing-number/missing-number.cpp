class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int sz=nums.size();
      sz=sz&1?sz*((sz+1)/2):(sz+1)*(sz/2);
      for(int i:nums)
        sz-=i;
      return sz;
    }
};