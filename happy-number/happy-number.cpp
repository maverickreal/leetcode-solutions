class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> ht;
        return func(n,ht);
    }
    bool func(int n, unordered_set<int> &ht)

{

	if (n == 1)

		return true;

	if (ht.find(n) != ht.end())

		return false;

	int g = 0;

	ht.insert(n);

	while (n)

	{

		g += pow(n % 10, 2);

		n /= 10;

	}

	return func(g, ht);

}
};