class Solution {
public:
    vector<string> uncommonFromSentences(string x, string y) {
        unordered_map<string, int> *ump = new unordered_map<string, int>;

int i = 0;

while (i < x.length())

{

	int j = i;

	while (j < x.length() and x[j] != ' ')

		++j;

	(*ump)[x.substr(i, j - i)]++;

	while (j < x.length() and x[j] == ' ')

		++j;

	i = j;

}

i = 0;

while (i < y.length())

{

	int j = i;

	while (j < y.length() and y[j] != ' ')

		++j;

	(*ump)[y.substr(i, j - i)]++;

	while (j < y.length() and y[j] == ' ')

		++j;

	i = j;

}

vector<string> ans;

for (auto i : (*ump))

{

	if (i.second == 1)

		ans.push_back(i.first);

}

delete ump;

return ans;
    }
};