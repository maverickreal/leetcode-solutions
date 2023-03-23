class Solution {
public:
    string removeKdigits(const string&str, int k){
        list<char>ans;
        int sz=str.size();
        for(int i=0; i<sz; ++i){
            int remPops=k-i+ans.size();
            while(!ans.empty() && ans.back()>str[i] && remPops>0){
                ans.pop_back();
                --remPops;
            }
            ans.push_back(str[i]);
        }
        while(ans.size()>sz-k){
            ans.pop_back();
        }
        while(!ans.empty() && ans.front()=='0'){
            ans.pop_front();
        }
        return (ans.empty() ? "0" : string(begin(ans), end(ans)));
    }
};