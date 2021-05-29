class Solution {
public:
    int singleNonDuplicate(vector<int>&v) {
        int i=0,j=v.size()-1;
        if(!j)
            return v[0];
        while(i<=j){
        	if(v[i]!=v[i+1])
        		return v[i];
        	if(v[j]!=v[j-1])
        		return v[j];
        	i+=2;
        	j-=2;
        }
        return -1;
    }
};