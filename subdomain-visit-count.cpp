class Solution {
public:
    void alpha(unordered_map<string, int> *ump, string s)

{

	int n = stoi(s);

	s.erase(0, to_string(n).length() + 1);

	(*ump)[s] += n;

	int x = s.find('.');

	while (x != string::npos)

	{

		(*ump)[s.substr(x + 1, s.length() - x - 1)] += n;

		x = s.find('.', x + 1);

	}

}

vector<string> subdomainVisits(vector<string> &v)

{

	unordered_map<string, int> *ump = new unordered_map<string, int>;

	for (string i : v)

		alpha(ump, i);

	vector<string> ans;

	for (auto i : *ump)

		ans.push_back(to_string(i.second) + " " + i.first);

	delete ump;

	return ans;

}
};