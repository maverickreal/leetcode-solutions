class Solution {
public:
    int maxArea(vector<int>& v) {
        	int a=0,i=0,j=v.size()-1;

	while(j>i){

		a=max(a,(min(v[i],v[j]))*(j-i));

		if(v[i]<v[j])

			++i;

		else

			--j;

	}

	return a;
    }
};