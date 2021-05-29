class Solution {
public:
    int distributeCandies(vector<int>& v) {
        unordered_set<int> ht;

for (int i : v)

	ht.insert(i);

return min(ht.size(), v.size() / 2);
    }
};