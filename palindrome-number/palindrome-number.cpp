class Solution {
public:
    bool isPalindrome(int x) {
        

	if (x < 0)

		return false;

	if (x < 10)

		return true;

	vector<int> v;

	while (x != 0)

	{

		v.push_back(x % 10);

		x /= 10;

	}

	int i = 0, j = v.size() - 1;

	while (i <= j)

	{

		if (v[i] != v[j])

			return false;

		++i;

		--j;

	}

	return true;
    }
};