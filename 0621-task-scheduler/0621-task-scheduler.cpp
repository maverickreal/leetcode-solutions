class Solution {
public:
    int leastInterval(vector<char>&v, int n) {
        vector<int>ump(26);
        for(char ch : v){
            ++ump[ch-'A'];
        }
        sort(begin(ump), end(ump));
        int newFreeSlots = n * (ump[25]-1);
        for(int i=24; i>-1; --i){
            newFreeSlots-=min(ump[25]-1, ump[i]);
        }
        return max(0, newFreeSlots) + v.size();
    }
};