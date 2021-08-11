class Solution {
public://"-000000000000001"
    int myAtoi(string&s) {
      if(s.empty() or (s[0]!='-' and s[0]!='+' and s[0]!=' ' and (s[0]<48 or s[0]>57)))
          return 0;
        bool sign=false;
        int i=-1,sz=s.length();
        while(++i<sz){
        if(s[i]=='-' or s[i]=='+'){
          if(s[i+1]<48 or s[i+1]>57)
            return 0;
          sign=s[i]=='-';
          ++i;
          break;
        }
        if(s[i]>47 and s[i]<58)
          break;
        if(s[i]!=' ')
          return 0;
        }
        if(s[i]=='0'){
        while(i<sz and s[i]=='0')
          ++i;
        if(s[i]<48 or s[i]>57)
          return 0;
        }
        if(s[i]<48 or s[i]>57)
          ++i;
        string res="";
        while(i<sz){
          if(!(s[i]>47 and s[i]<58))
            break;
          res.push_back(s[i]);
          ++i;
        }
        sz=res.length();
        if(sz>10)
          return sign?INT_MIN:INT_MAX;
        int ans=0,ten=-1;
        for(int i=sz-1;i>-1;--i){
          if(++ten>9)
            return sign?INT_MIN:INT_MAX;
          int x=res[i]-'0',y=pow(10,ten);
          if(x and y>INT_MAX/x or INT_MAX-(x*y)<ans)
            return sign?INT_MIN:INT_MAX;
          ans+=x*y;
        }
        return ans>INT_MAX?(sign?INT_MIN:INT_MAX):ans*(sign?-1:1);
    }
};