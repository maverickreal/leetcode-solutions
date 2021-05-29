class Solution {
public:
    int islandPerimeter(vector<vector<int>>& v) {
        	if (!v.size())

		return 0;

	int ans = 0;

	for (int i = 0; i < v.size(); ++i)

	{

		for (int j = 0; j < v[0].size(); ++j)

		{

			if (v[i][j])

			{

				if (j + 1 >= v[0].size() or !v[i][j + 1])

					++ans;

				if (j - 1 < 0 or !v[i][j - 1])

					++ans;

				if (i + 1 >= v.size() or !v[i + 1][j])

					++ans;

				if (i - 1 < 0 or !v[i - 1][j])

					++ans;

			}

		}

	}

	return ans;
    }
};