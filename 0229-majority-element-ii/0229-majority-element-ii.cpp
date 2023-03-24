class Solution {
public:
    vector<int> majorityElement(vector<int>&v) {
        int sz=v.size();
        int x=0, cx=0, y=0, cy=0;
        for(int z : v){
            if(cx==0 && (cy==0 || z!=y)){
                cx=1, x=z;
                continue;
            }
            if(cy==0 && (cx==0 || x!=z)){
                cy=1, y=z;
                continue;
            }
            if(z==x){
                ++cx;
                continue;
            }
            if(z==y){
                ++cy;
                continue;
            }
            --cx, --cy;
        }
        cx=cy=0;
        for(int z : v){
            cx+=z==x, cy+=z==y;
        }
        vector<int>ans;
        if(cx>sz/3){
            ans.push_back(x);
        }
        if(cy>sz/3 && (ans.empty() || ans.back()!=y)){
            ans.push_back(y);
        }
        return ans;
    }
};