class Solution {
public:
    void func(string&str){
        for(int i=0; i<str.size(); ++i){
            if(str[i]!='#'){
                continue;
            }
            if(i>0){
                str.erase(begin(str)+i-1);
                --i;
            }
            str.erase(begin(str)+i);
            --i;
        }
    }
    bool backspaceCompare(string s, string t) {
        int szs = s.size(), szt = t.size();
        func(s); func(t);
        return (s==t);
    }
};