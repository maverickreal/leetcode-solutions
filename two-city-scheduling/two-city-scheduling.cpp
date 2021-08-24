class Solution {
	static bool cmp(const vector<int>&a,const vector<int>&b){
		return a[0]-a[1]<b[0]-b[1];
	}
public:
    int twoCitySchedCost(vector<vector<int>>&v) {
        sort(v.begin(),v.end(),cmp);
        int sz=v.size()>>1,res=0;
        for(int i=0;i<sz;++i)
        	res+=v[i][0]+v[i+sz][1];
        return res;
    }
};