class Solution {
public:
    vector<int> secondGreaterElement(const vector<int>&v) {
        int sz=v.size();
        stack<int>nong, nosng;
        vector<int>ans(sz, -1);
        for(int i=0; i<sz; ++i){
            while(!nosng.empty() && v[i]>v[nosng.top()]){
                ans[nosng.top()]=v[i];
                nosng.pop();
            }
            stack<int>tmp;
            while(!nong.empty() && v[i]>v[nong.top()]){
                tmp.push(nong.top());
                nong.pop();
            }
            while(!tmp.empty()){
                nosng.push(tmp.top());
                tmp.pop();
            }
            nong.push(i);
        }
        return ans;
    }
};