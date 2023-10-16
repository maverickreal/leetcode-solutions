class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int>ans, nums;
        int preCnt=0;
        for(int i=0; i<words.size(); ++i){
            if(words[i]=="prev"){
                ++preCnt;
                if(preCnt>nums.size()){
                    ans.push_back(-1);
                } else{
                    ans.push_back(nums[nums.size()-preCnt]);
                }
            } else{
                preCnt=0;
                nums.push_back(stoi(words[i]));
            }
        }
        return ans;
    }
};