class Solution {
public:
    int shortestSubarray(vector<int>& nums, long long k) {
        long long n=nums.size(), sum=0, ans=INT_MAX;
        vector<long long>preVal = {0}, preInd = {-1};
        for(long long i=0; i<n; ++i){
            sum+=nums[i];
            if(sum>=k){
                ans = min(ans, i+1);
            }
            if(nums[i]>=k){
                return 1;
            }
            auto it = upper_bound(begin(preVal), end(preVal), sum-k);
            if(it!=begin(preVal)){
                --it;
                int ind = preInd[it-begin(preVal)];
                ans = min(ans, i-ind);
            }
            while(!preVal.empty() && sum<=preVal.back()){
                preVal.pop_back(); preInd.pop_back();
            }
            preVal.push_back(sum); preInd.push_back(i);
        }
        return (ans==INT_MAX?-1:ans);
    }
};