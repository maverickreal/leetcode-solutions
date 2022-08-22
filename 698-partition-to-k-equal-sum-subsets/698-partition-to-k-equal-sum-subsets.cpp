class Solution {
public:
    int dp[65537];
bool solve(vector<int> &nums, int mask, int k, int cnt, int sum, int target)
{
    if(cnt==k)
        return true;
    
    if(mask == (1<<nums.size())-1)
        return false;
    
    if(dp[mask]!=-1)
        return dp[mask];
    
    bool res=false;
    for(int i=0;i<nums.size();i++)
    {
        if((mask & (1<<i))==0)
        {
            mask = mask^(1<<i);
            if(nums[i]+sum<target)
            {
                res |= solve(nums, mask, k, cnt, sum+nums[i],target);
                if(res==true)
                    break;
            }
            else if(nums[i]+sum==target)
            {
                res |= solve(nums, mask, k, cnt+1, 0, target);
                if(res==true)
                    break;
            }
            mask = mask^(1<<i);
        }
    }
    
    return dp[mask]=res;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int mask = 0;
    memset(dp,-1,sizeof(dp));
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum += nums[i];
    }
    if(sum%k!=0)
        return false;
    int target = sum/k;
    return solve(nums, mask, k, 0, 0, target);
}
};