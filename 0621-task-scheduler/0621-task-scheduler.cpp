class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26);
        for(char ch : tasks){
            ++freq[ch-'A'];
        }
        sort(begin(freq), end(freq));
        int freeTimeUnits = n * (freq.back() - 1);
        for(int i=24; i>-1; --i){
            if(freq[i]==freq.back()){
                freeTimeUnits -= freq[i] - 1;
            } else{
                freeTimeUnits -= freq[i];
            }
        }
        return tasks.size() + max(0, freeTimeUnits);
    }
};