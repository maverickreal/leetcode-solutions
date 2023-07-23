class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>&v, char sep) {
        vector<string>ans;
        for(const string&str : v){
            string cur;
            for(const char&ch : str){
                if(ch==sep){
                    if(!cur.empty()){
                        ans.push_back(cur);
                        cur.clear();
                    }
                } else{
                    cur.push_back(ch);
                }
            }
            if(!cur.empty()){
                ans.push_back(cur);
            }
        }
        return ans;
    }
};