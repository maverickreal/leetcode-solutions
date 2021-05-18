class Solution {
public:
    int countSegments(string s) {
        	if (s.length() == 0)

		return 0;

	if (s.length() == 1)

		return (s[0] == ' ' ? 0 : 1);

	int ans = 0, i = 0;

	while (i < s.length())

	{

		int j = i;

		while (j < s.length() and s[j] != ' ')

			++j;

		if (j - i)

		{

			++ans;

			i = j;

		}

		++i;

	}

	return ans;
    }
};