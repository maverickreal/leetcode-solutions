class Solution {
public:
    string addBinary(string s1, string s2) {
        if (s1.length() == 1 and s2.length() == 1)

	{

		if (s1[0] == '0' and s2[0] == '0')

			return "0";

		if (s1[0] == '1' and s2[0] == '1')

			return "10";

		return "1";

	}

	if (s1.length() != s2.length())

	{

		if (s1.length() < s2.length())

		{

			reverse(s1.begin(), s1.end());

			while (s1.length() != s2.length())

				s1.push_back('0');

			reverse(s1.begin(), s1.end());

		}

		else

		{

			reverse(s2.begin(), s2.end());

			while (s1.length() != s2.length())

				s2.push_back('0');

			reverse(s2.begin(), s2.end());

		}

	}

	int i = s1.length() - 1, rem = 0;

	string ans = "";

	for (int u = 0; u < s2.length(); ++u)

		ans.push_back('0');

	while (i > -1)

	{

		int g = s1[i] % 48 + s2[i] % 48 + rem;

		ans[i] = to_string(g % 2)[0];

		rem = g / 2;

		i--;

	}

	if (rem)

	{

		reverse(ans.begin(), ans.end());

		ans.push_back('1');

		reverse(ans.begin(), ans.end());

	}

	return ans;
    }
};