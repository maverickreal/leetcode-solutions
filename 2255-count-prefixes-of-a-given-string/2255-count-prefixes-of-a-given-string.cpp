class Solution {
public:
    int countPrefixes(vector<string>&v, string&s) {
        int res=0;
        for(const string&str:v){
            bool fl=true;
            if(str.length()>s.length())
                continue;
            for(int i=0;i<str.length();++i){
                if(s[i]!=str[i]){
                    fl=false;
                    break;
                }
            }
            if(fl)
                ++res;
        }
        return res;
    }
};