class Solution {
public:
    string removeDigit(string&s, char digit) {
        string res=s;
        int sz=s.length();
        bool fl=false;
        for(int i=0;i<sz;++i){
            if(s[i]!=digit)
                continue;
            string tmp=s.substr(0, i)+s.substr(i+1, sz-i-1);
            if(!fl){
                fl=true;
                res=tmp;
                continue;
            }
            res=max(res, tmp);
        }
        return res;
    }
};