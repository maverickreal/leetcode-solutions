class Solution {
public:
    int sz;
    bool isOpen(char ch){
        return (ch=='(' || ch=='{' || ch=='[');
    }
    char getClosing(char ch){
        if(ch=='('){
            return ')';
        }
        if(ch=='{'){
            return '}';
        }
        return ']';
    }
    int getClosingPos(const string&str, int start, char toFind){
        int pa=0, cu=0, br=0;
        for(int i=start; i<sz; ++i){
            if(str[i]==toFind && pa==0 && cu==0 && br==0){
                return i;
            }
            if(str[i]=='('){
                ++pa;
            } else if(str[i]=='{'){
                ++cu;
            } else if(str[i]=='['){
                ++br;
            } else if(str[i]==')'){
                --pa;
            } else if(str[i]=='}'){
                --cu;
            } else if(str[i]==']'){
                --br;
            }
        }
        return -1;
    }
    bool isValid(string s) {
        sz = s.size();
        for(int i=0; i<sz; ++i){
           if(s[i]=='#'){
               continue;
           }
            if(!isOpen(s[i])){
                return false;
            }
            int found = getClosingPos(s, i+1, getClosing(s[i]));
            if(found==-1){
                return false;
            }
            s[found]='#';
        }
        return true;
    }
};