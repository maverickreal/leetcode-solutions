class Solution {
public:
    int firstUniqChar(string s) {
        	if (s.length() == 0)

		return -1;

	if (s.length() == 1)

		return 0;

	if (s.length() == 2)

		return (s[0] == s[1] ? -1 : 0);

	int ar[26] = {0};

	for (int i = 0; i < s.length(); ++i)

		ar[s[i] % 97]++;

	for (int i = 0; i < s.length(); ++i)

	{

		if (ar[s[i] % 97] == 1)

			return i;

	}

	return -1;
    }
};