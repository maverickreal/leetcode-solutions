class Solution {
public:
int sz;
vector<vector<int>>dp;
vector<int>ps;
 bool isps(const int&num){
     int l=0, r=ps.size()-1;
     while(l<=r){
         int m=l+((r-l)>>1);
         if(ps[m]==num){
             return 1;
         }
         if(ps[m]<num){
             l=m+1;
         } else{
             r=m-1;
         }
     }
     return 0;
 }
 int func(const vector<int>&v, int pre, int bm){
    if(bm==(1<<sz)-1){
        return 1;
    }
     // cout<<pre<<' '<<bm<<endl;
    if(dp[bm][pre]>-1){
        return dp[bm][pre];
    }
    dp[bm][pre]=0;
    int prev=-1;
    for(int i=0; i<sz; ++i){
        if((prev==-1 || v[prev]!=v[i]) && !(bm&(1<<i)) && (pre==sz || isps(v[pre]+v[i]))){
            dp[bm][pre]+=func(v, i, bm|(1<<i));
            prev=i;
        }
    }
    return dp[bm][pre];
 }
 int numSquarefulPerms(vector<int>& v) {
    sz = v.size();
    sort(begin(v), end(v));
    for(int i=0; i*i<=2000000000; ++i){
     ps.push_back(i*i);
    }
    dp.assign(1<<sz, vector<int>(sz+1, -1));
    int bm = 0;
    return func(v, sz, bm);
 }
};