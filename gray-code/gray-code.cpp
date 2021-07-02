class Solution {
public:
    vector<int> grayCode(int n) {
        unordered_set<int>ust={0};
        vector<int>res={0};
        while(res.size()<(1<<n)){
            long m=res.back();
            int i=0;
            while(ust.find(m^(1<<i))!=ust.end())
                  ++i;
            long tmp=m^(1<<i);
            // if((1<<i)>m)
            //     tmp=1<<i;
            ust.insert(tmp);
            res.push_back(tmp);
        }
        return res;
    }
};