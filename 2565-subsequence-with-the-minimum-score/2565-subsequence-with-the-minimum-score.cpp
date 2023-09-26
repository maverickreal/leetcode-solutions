class Solution {
public:
    int minimumScore(const string&a, const string&b) {
        int m=a.size(), n=b.size();
        vector<int>suf(n, -1);
        int j=n-1;
        for(int i=m-1; j>-1 && i>-1; --i){
            if(a[i]==b[j]){
                suf[j--] = i;
            }
        }
        if(j==-1){
            return 0;
        }
        int ans=j+1;
        for(int i=0, k=0; i<m && k<n; ++i){
            if(a[i]!=b[k]){
                continue;
            }
            while(j<n && suf[j]<=i){
                ++j;
            }
            ans = min(ans, max(0, j-k-1));
            ++k;
        }
        return ans;
    }
};