class Solution {
public:
    int peakIndexInMountainArray(vector<int>&v) {
        int i=0,j=v.size()-1;
        while(i<j){
            int m=i+((j-i)>>1);
            int l=(m?v[m-1]:-1);
            int r=(m<v.size()-1?v[m+1]:1000001);
            if(l<v[m] && r<v[m])
                break;
            if(v[m]>l && r>v[m]){
                if(m<v.size()-1)
                    i=m+1;
                else
                    break;
            }
            else{
                if(m)
                    j=m-1;
                else
                    break;
            }
        }
        return i+((j-i)>>1);
    }
};