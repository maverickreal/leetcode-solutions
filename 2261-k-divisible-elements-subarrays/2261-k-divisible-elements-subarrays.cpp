class Solution {
public:
    int countDistinct(vector<int>&v, int k, int p) {
        unordered_set<string>ust;
        int sz=v.size(), res=0;
        for(int i=0;i<sz;++i){
            int j=i, cnt=0;
            for(;j<sz && cnt<=k;++j){
                if(v[j]%p==0)
                    ++cnt;
            }
            --j;
            if(cnt>k)
                --j;
            string s;
            for(int l=i;l<=j;++l){
                s.append(to_string(v[l]));
                s.push_back(',');
                if(ust.find(s)==ust.end()){
                    ++res;
                    ust.insert(s);
                }
            }
        }
        return res;
    }
};