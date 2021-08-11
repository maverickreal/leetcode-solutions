class Solution {
public:
    bool checkRecord(string s) {
        	int a = 0, l = 0, i = 0;

	while (i < s.length())

	{

		if (s[i] == 'A')

		{

			++a;

			++i;

			if (a > 1)

				return false;

		}

		else if (s[i] == 'L')

		{

			int j = i + 1;

			while (j < s.length() and s[j] == 'L')

			{

				++j;

				if (j - i > 2)

					return false;

			}

			i = j;

		}

		else

			++i;

	}

	return true;
    }
};