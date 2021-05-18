class Solution {
public:
    bool isAnagram(string s, string t)

	{

		if (s.length() != t.length())

		{

			//cout << "1  ";

			return false;

		}

		short ht[26] = {0};

		for (int i = 0; i < s.length(); ++i)

			ht[s[i] % 97]++;

		for (int i = 0; i < t.length(); ++i)

		{

			if (ht[t[i] % 97] == 0)

			{

				//cout << "2  ";

				return false;

			}

			ht[t[i] % 97]--;

		}

		for (int i = 0; i < 26; ++i)

		{

			if (ht[i])

				return false;

		}

		return true;

	}

};