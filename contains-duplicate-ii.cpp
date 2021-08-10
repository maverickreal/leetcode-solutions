class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()<2)
            return false;
        unordered_multimap<int, int> ht;

typedef unordered_multimap<int, int>::iterator umit;

for (int i = 0; i < nums.size(); ++i)

{

	pair<umit, umit> p = ht.equal_range(nums[i]);

	if (p.first != ht.end())

	{

		umit tmp = p.first;

		while (tmp != p.second)

		{

			if (i - tmp->second <= k)

				return true;

			++tmp;

		}

	}

	ht.insert(make_pair(nums[i], i));

}

return false;
    }
};