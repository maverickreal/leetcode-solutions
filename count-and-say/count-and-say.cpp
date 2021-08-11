class Solution

{

  public:

	string ext(string y, int n)

	{

		if (n == 0)

			return y;

		string z = "";

		int i = 0;

		while (i < y.length())

		{

			int j = i + 1;

			while (j < y.length() and y[j] == y[j - 1])

				++j;

			z += to_string(j - i) + y[i];

			i = j;

		}

		return ext(z, n - 1);

	}

	string countAndSay(int n)

	{

		string y = "1";

		if (n == 1)

			return y;

		return ext(y, n - 1);

	}

};