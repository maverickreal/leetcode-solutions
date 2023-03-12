class Solution {
public:
    bool isValid(const char&ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;
        for(int i=left;i<=right;++i){
            if(isValid(words[i].front()) && isValid(words[i].back())){
                ++ans;
            }
        }
        return ans;
    }
};