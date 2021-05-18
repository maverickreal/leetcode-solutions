class Solution {
public:
    string reverseVowels(string s) {
        	if (s.length() < 2)

		return s;

	int i = 0, j = s.length() - 1;

	while (i < j)

	{

		if (s[i] == s[j])

		{

			++i;

			--j;

		}

		else if ((s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U') and (s[j] == 'a' or s[j] == 'e' or s[j] == 'i' or s[j] == 'o' or s[j] == 'u' or s[j] == 'A' or s[j] == 'E' or s[j] == 'I' or s[j] == 'O' or s[j] == 'U'))

		{

			char tmp = s[i];

			s[i] = s[j];

			s[j] = tmp;

			++i;

			--j;

		}

		else

		{

			if (s[i] != 'a' and s[i] != 'e' and s[i] != 'i' and s[i] != 'o' and s[i] != 'u' and s[i] != 'A' and s[i] != 'E' and s[i] != 'I' and s[i] != 'O' and s[i] != 'U')

				++i;

			if (s[j] != 'a' and s[j] != 'e' and s[j] != 'i' and s[j] != 'o' and s[j] != 'u' and s[j] != 'A' and s[j] != 'E' and s[j] != 'I' and s[j] != 'O' and s[j] != 'U')

				--j;

		}

	}

	return s;
    }
};