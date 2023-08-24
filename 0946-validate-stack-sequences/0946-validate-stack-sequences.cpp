class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = 0;
        stack<int>st;
        for(int i=0; i<pushed.size(); ++i){
            if(j==popped.size()){
                return false;
            }
            st.push(pushed[i]);
            while(!st.empty() && j<size(popped) && st.top()==popped[j]){
                st.pop();
                ++j;
            }
        }
        return (j==popped.size());
    }
};