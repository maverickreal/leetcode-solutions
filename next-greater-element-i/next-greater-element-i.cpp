class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        	vector<int> ans;

	for (int i = 0; i < nums1.size(); ++i)

		ans.push_back(-1);

	for (int it = 0; it < nums1.size(); ++it)

	{

		int ti = nums2.size() - 1;

		while (nums1[it] != nums2[ti])

		{

			if (nums2[ti] > nums1[it])

				ans[it] = nums2[ti];

			--ti;

		}

	}

	return ans;
    }
};