class Solution {
public:
    int lengthOfLIS(vector<int>& num) {
        int sz=num.size(),res=1;
        vector<int>v(sz,1);
        for(int i=0;i<sz;++i){
        	for(int j=0;j<i;++j)
        		if(num[j]<num[i] && v[i]<=v[j])
        			v[i]=v[j]+1;
        	res=max(res,v[i]);
        }
        return res;
    }
};