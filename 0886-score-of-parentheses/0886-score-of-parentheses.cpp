class Solution {
public:
    int helper(const string&str, int l, int r){
        if(l>=r){
            return 0;
        }
        int ans=0, bal=0;
        for(int i=l, j=l; i<=r; ++i){
            bal += str[i]=='(' ? 1 : -1;
            if(bal==0){
                int rec = helper(str, j+1, i-1);
                ans += rec ? 2*rec : 1;
                j=i+1;
            }
        }
        return ans;
    }
    int scoreOfParentheses(string s) {
      return helper(s, 0, s.size()-1);  
    }
};