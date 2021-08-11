class Solution {
public:
    int findLHS(vector<int>& v) {
        if(v.size()<2)
            return 0;
        map<int,int> mp;

for (int i : v)

	mp[i]++;

int ans = 0;

auto ti = mp.begin();

for (auto it = mp.begin();it != mp.end(); ++it)

{

	if (it == mp.begin())

		continue;

	if (it->second + ti->second > ans and it->first - ti->first == 1)

	{

		ans = it->second + ti->second;

	}

	advance(ti, 1);

}

return ans;
    }
};