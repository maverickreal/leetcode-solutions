class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

	int ar[22] = {0};

	ar[0] = 100;

	ar[1] = 500;

	ar[6] = 1;

	ar[9] = 50;

	ar[10] = 1000;

	ar[19] = 5;

	ar[21] = 10;

	if (s.length() == 1)

		return ar[s[0] % 67];

	int i = 0;

	while (i < s.length())

	{

		int j = i;

		while (j < s.length() - 1 and s[j + 1] == s[j])

			++j;

		if (ar[s[j + 1] % 67] > ar[s[i] % 67] and i < s.length() - 1 and j < s.length() - 1)

			ans -= (j - i + 1) * ar[s[i] % 67];

		else

			ans += (j - i + 1) * ar[s[i] % 67];

		i = j + 1;

	}

	return ans;
    }
};