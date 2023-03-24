class Solution {
public:
    int majorityElement(const vector<int>&v) {
        int sz=v.size(), ele=0, cnt=0;
        for(int it:v){
            if(cnt==0){
                ele=it, cnt=1;
            }
            else{
                cnt+=it==ele?1:-1;
            }
        }
        int votes = 0;
        for(int it:v){
            votes+=it==ele;
        }
        return (votes > sz/2 ? ele : -1);
    }
};