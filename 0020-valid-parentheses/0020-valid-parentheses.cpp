class Solution {
public:
    char getClosing(char ch){
        if(ch=='('){
            return ')';
        }
        if(ch=='{'){
            return '}';
        }
        return ']';
    }
    bool isOpening(char ch){
        return (ch=='(' || ch=='{' || ch=='[');
    }
    int find(const string&str, int start, char toFind){
        int pa=0, cu=0, br=0;
        for(int i=start; i<str.size(); ++i){
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
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='#'){
                continue;
            }
            if(!isOpening(s[i])){
                return false;
            }
            int found = find(s, i+1, getClosing(s[i]));
            if(found==-1){
                return false;
            }
            s[found]='#';
        }
        return true;
    }
};