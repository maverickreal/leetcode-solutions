class Solution {
public:
    int monotoneIncreasingDigits(int n) {
      string s=to_string(n);
      int sz=s.length();
      for(int i=sz-1;i;--i){
        if(s[i]<s[i-1]){
          --s[i-1];
          --s[i];
        for(int j=i; j<sz;++j)
            if(s[j]<s[j-1])
              s[j]='9';
          }
        }
        return stoi(s);
      }
    };