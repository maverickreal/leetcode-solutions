class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
        int tmp=0;
        bool fl;
        string res;
        for(int i=0;i<s.length();++i){
            tmp+=s[i]-'0';
            fl=true;
            if(!((i+1)%k)){
                res.append(to_string(tmp));
                tmp=0;
                fl=false;
            }
        }
        if(fl)
            res.append(to_string(tmp));
        s=res;
        }
        return s;
    }
};