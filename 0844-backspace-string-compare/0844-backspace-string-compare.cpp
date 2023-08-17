class Solution {
public:
    void operate(string&str){
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
        operate(s); operate(t);
        return (s==t);
    }
};