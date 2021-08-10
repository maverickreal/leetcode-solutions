class Solution {
public:
    int strStr(string x, string y) {
        	if (y.length() == 0)

		return 0;

	int sz = x.length() - y.length();

	if (sz < 0)

		return -1;

	for (auto it = x.begin(); it <= x.begin() + sz; ++it)

	{

		if (*it == y[0])

		{

			auto t1 = it, t2 = y.begin();

			while (t2 != y.end())

			{

				if (*t1 != *t2)

					break;

				if (t2 == y.begin() + y.length() - 1)

					return distance(x.begin(), it);

				++t1;

				++t2;

			}

		}

	}

	return -1;
    }
};