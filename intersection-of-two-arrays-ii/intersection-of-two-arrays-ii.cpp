class Solution {
public:
    vector<int> intersect(vector<int>& v1,vector<int>& v2) {
        vector<int> ans;

unordered_multiset<int> umst(v1.begin(), v1.end());

for (auto i : v2)

{

	if (umst.find(i) != umst.end())

	{

		ans.push_back(i);

		umst.erase(umst.find(i));

	}

}

return ans;
    }
};