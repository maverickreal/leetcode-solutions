class Solution {
public:
    bool wordPattern(string p, string s) {
        	int i = 0, j = 0;

	unordered_map<char, string> ht;

	unordered_set<string> st;

	while (i < s.length())

	{

		if (j >= p.length())

			return false;

		int k = i;

		while (k < s.length() and s[k] != ' ')

			++k;

		if (ht.find(p[j]) != ht.end())

		{

			if (ht[p[j]] != s.substr(i, k - i))

				return false;

		}

		else

		{

			if (st.find(s.substr(i, k - i)) != st.end())

				return false;

			st.insert(s.substr(i, k - i));

			ht[p[j]] = s.substr(i, k - i);

		}

		++j;

		i = k + 1;

	}
    if(j<p.size())
        return false;
	return true;
    }
};