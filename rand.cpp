#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
const int maxn = 512 + 1;
string ss = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
int ln = ss.length();
int cnt = 0;
vector<int> used;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
long long Rand(long long l, long long h)
{
	assert(l <= h);
	return l + rd() * 1LL * rd() % (h - l + 1);
}
void reset()
{
	while (!used.empty())
		used.pop_back();
}

bool isused(int n)
{
	for (auto i : used)
		if (n == i)
			return true;
	return false;
}

int main()
{
	freopen("permutation.log", "w", stdout);
	int T = 16384;
	while (T--)
	{
		string outp = "";
		while (outp.length() != ln)
		{
			int x = (abs(Rand(16,256)) + T) % ln;
			if (!isused(x))
			{
				used.push_back(x);
				outp += ss[x];
			}
		}
		cout << outp << "\n";
		reset();
		ss = outp;
		ln = ss.length();
	}
	return 0;
}
