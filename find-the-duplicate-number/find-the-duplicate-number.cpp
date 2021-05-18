class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int sz=v.size();
        vector<bool>bit(sz);
        for(const int&i:v){
        	if(bit[i])
        		return i;
        	bit[i]=true;
        }
        return -1;
    }
};