class Solution {
public:
    string reverseOnlyLetters(string&s) {
        int i=0,j=s.length()-1;
        while(i<j){
            char ch=s[i];
            if(ch<65|| ch>122 || (ch>90 && ch<97)){
                ++i;
                continue;
            }
            ch=s[j];
            if(ch<65|| ch>122 || (ch>90 && ch<97)){
                --j;
                continue;
            }
            ch=s[i];
            s[i]=s[j];
            s[j]=ch;
            ++i,--j;
        }
        return s;
    }
};
//65 90 97 122