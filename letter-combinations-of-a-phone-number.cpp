class Solution {
public:
vector<string>res,v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void func(string&d,string s="",int in=0){
if(in>=d.length()){
res.push_back(s);
return;
}
for(char&ch:v[d[in]-'0']){
string tmp=s;
tmp.push_back(ch);
func(d,tmp,in+1);
}
}
    vector<string> letterCombinations(string&d) {
        if(d.empty())
                return {};
func(d);
return res;
    }
};