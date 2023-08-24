class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j = 0;
        for(int i=0; i<pushed.size(); ++i){
            if(j==popped.size()){
                return false;
            }
            st.push(pushed[i]);
            while(!st.empty() && j<popped.size() && popped[j]==st.top()){
                st.pop();
                ++j;
            }
        }
        return (j==popped.size());
    }
};