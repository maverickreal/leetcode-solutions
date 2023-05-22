class Solution{
    public:
    vector<int> findErrorNums(vector<int>&v){
        int n=v.size();
        int xo = 0;
        for(int it:v){
            xo^=it;
        }
        for(int i=1; i<=n; ++i){
            xo^=i;
        }
        int rsb = xo & -xo, setNum = 0, unsetNum = 0;
        for(int it : v){
            if(it & rsb){
                setNum^=it;
            }
            else{
                unsetNum^=it;
            }
        }
        for(int it=1; it<=n; ++it){
            if(it & rsb){
                setNum^=it;
            }
            else{
                unsetNum^=it;
            }
        }
        for(int it:v){
            if(it==unsetNum){
                return {unsetNum, setNum};
            }
        }
        return {setNum, unsetNum};
    }
};