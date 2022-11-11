class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>ust;
        for(int it:nums){
            ust.insert(it);
        }
        int ans=0;
        for(int it:nums){
            if(ust.find(it+1)!=ust.end()){
                continue;
            }
            int dis=1, ti=it;
            while(ust.find(ti-1)!=ust.end()){
                ++dis, --ti;
            }
            ans=max(ans, dis);
        }
        return ans;
    }
};