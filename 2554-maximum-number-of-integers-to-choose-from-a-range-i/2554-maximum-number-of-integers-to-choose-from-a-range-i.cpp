class Solution {
public:
    int maxCount(vector<int>&ban, int n, int mx) {
        int ans=0, sum=0;
        unordered_set<int>ust(begin(ban), end(ban));
        for(int i=1;i<=n;++i){
            if(ust.find(i)!=end(ust)){
                continue;
            }
            if(sum+i>mx){
                break;
            }
            sum+=i, ++ans;
        }
        return ans;
    }
};