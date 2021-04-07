class Solution {
public:
    string longestPalindrome(string&s) {
        string res=s.substr(0,1);
        int i=0,sz=s.length();
        while(++i<sz){
            if(s[i]==s[i-1]){
                int j=i-1,k=i;
                while(j>-1 && k<sz && s[j]==s[k]){
                    --j;
                    ++k;
                }
                if(res.length()<k-j-1)
                    res=s.substr(j+1,k-j-1);
            }
            if(i>1 && s[i]==s[i-2]){
                int j=i-2,k=i;
                while(j>-1 && k<sz && s[k]==s[j]){
                    ++k;
                    --j;
                }
            if(k-j-1>res.length())
                res=s.substr(j+1,k-j-1);

            }
        }
        return res;
    }
};