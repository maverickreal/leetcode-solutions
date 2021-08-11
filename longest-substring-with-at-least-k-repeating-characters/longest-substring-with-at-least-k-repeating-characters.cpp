class Solution {
public:
	int func(string&s,int b,int e,const int&k){
		if(e-b+1<k)
			return 0;
		vector<int>v(26);
		for(int i=b;i<=e;++i)
			++v[s[i]-'a'];
		for(int i=b;i<=e;++i){
			if(v[s[i]-'a']<k){
				int j=i;
				while(j<=e &&  v[s[j]-'a']<k)
					++j;
				return max(func(s,b,i-1,k), func(s,j,e,k));
			}
		}
		return e-b+1;
	}
    int longestSubstring(string&s, int k) {
        return func(s,0,s.length()-1,k);
    }
};