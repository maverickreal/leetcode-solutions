class Solution {
public:
    
vector<vector<int>>dp;

int sz;

bool func(const string&str, int in, int op){
    if(op<0){
        return 0;
    }
    if(in==sz){
	    return (op==0);
    }
    if(dp[in][op]>-1){
	    return dp[in][op];
    }
    bool ans=0;
    if(str[in]=='('){
	    ans=func(str, in+1, op+1);
    }
    else if(str[in]==')'){
	    ans=func(str, in+1, op-1);
    }
    else{
	    ans=func(str, in+1, op) || func(str, in+1, op+1) || func(str, in+1, op-1);
    }
    return (dp[in][op]=ans);
}

bool checkValidString(const string&str){
	sz=str.size();
    dp.resize(sz, vector<int>(sz, -1));
    return func(str, 0, 0);
}
};