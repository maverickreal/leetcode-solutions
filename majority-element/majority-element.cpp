class Solution {
public:
    int majorityElement(vector<int>& v) {
        	sort(v.begin(),v.end());
    if(v.size()<3)
        return v[0];
	int i=0;

	while(i<v.size()-1){

		int cnt=1,j=i;

		while(v[j+1]==v[j]){

			++cnt;
            ++j;

			if(cnt>v.size()/2)

				return v[i];

		}

		i=j+1;

	}

	return 0;
    }
};