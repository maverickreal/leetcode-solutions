class Solution {
public:
    bool fair(string &s2, string &s1, unordered_map<char, int> *ump, int i = 0)

{

	if (i == s2.length() and i < s1.length())

		return false;

	if (i == s1.length() and i < s2.length())

		return true;

	if (i == s1.length() and i == s2.length())

		return true;

	if ((*ump)[s2[i]] < (*ump)[s1[i]])

		return false;

	if (s2[i] == s1[i])

		return fair(s2, s1, ump, i + 1);

	return true;

}
    bool isAlienSorted(vector<string>& v, string s) {
        	unordered_map<char, int> *ump = new unordered_map<char, int>;

	for (int i = 0; i < s.length(); ++i)

		(*ump)[s[i]] = i;

	for (int i = 1; i < v.size(); ++i)

	{

		if (!fair(v[i], v[i - 1], ump))

			return false;

	}

	delete ump;

	return true;
    }
};