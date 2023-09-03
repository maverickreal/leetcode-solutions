class Solution {
public:
    long long countInterestingSubarrays(vector<int>&v, int mod, int k) {
        long long ans = 0, n = v.size(), cnt = 0;
        unordered_map<int, int>ump;
        for(int i=0; i<n; ++i){
            cnt+=((v[i]%mod)==k);
            ans+=(cnt%mod)==k;
            ans+=ump[(cnt-k+mod)%mod];
            ++ump[cnt%mod];
        }
        return ans;
    }
};