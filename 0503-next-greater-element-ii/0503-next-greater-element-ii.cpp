class Solution {
public:
vector<int> nextGreaterElements(vector<int>&v) {
	int sz=v.size();
	list<int>st;
vector<int>ans(sz, -1);
	for(int i=sz-1;i>-1;--i){
		while(!st.empty() && v[i]>=v[st.back()]){
			st.pop_back();
		}
		if(!st.empty()){
			ans[i]=st.back();
		}
		st.push_back(i);
	}
	for(int i=sz-1;i>-1;--i){
        if(ans[i]>-1){
            ans[i]=v[ans[i]];
            continue;
        }
        while(!st.empty() && v[st.back()]<=v[i]){
            st.pop_back();
        }
        if(!st.empty()){
            ans[i]=v[st.back()];
        }
    }
    return ans;
}
};