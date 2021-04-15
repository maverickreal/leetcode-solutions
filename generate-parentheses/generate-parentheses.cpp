class Solution {
public:
    vector<string>res;
    void func(const int&n,string s="",int o=0,int c=0){
        if(o==n && c==n){
            res.push_back(s);
            return;
        }
        if(o<n && c<=n)
            func(n,s+'(',1+o,c);
        if(o<=n && c<o)
            func(n,s+')',o,1+c);
    }
    vector<string> generateParenthesis(int n) {
        func(n);
        return res;
    }
};