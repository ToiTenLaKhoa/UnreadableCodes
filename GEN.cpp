#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define rand rd
long long Rand(long long l, long long h)
{
	assert(l <= h);
	return abs(l + rd() * 1LL * rd() % (h - l + 1));
}


// use any string in permutation.log for Hashcode
const string Hashcode = "";
string s;

void trim(string &s)
{
	string t = "";
	int i = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] == '\t')
		i++;
	for (i; i < s.length(); i++)
		t += s[i];
	s = t;
}

int ren(string name1, string name2)
{
	const char *str1 = name1.c_str();
	const char *str2 = name2.c_str();
	return (rename(str1, str2) != 0);
}

void die(string msg)
{
	cout << msg << endl;
	system("pause");
	exit(0);
}

int main()
{
	if (!Hashcode.length())
		die("Invalid Hashcode");

	cout << "enter your file name > ";
	string name;
	cin >> name;

	if (ren(name, "old_" + name))
		die("File not found");

	ifstream ifile("old_" + name);
	ofstream ofile(name);

	int cnt = 1;
	while (!ifile.eof())
	{
		getline(ifile, s);
		trim(s);
		if (s != "")
		{
			ofile << s << "\n";
			int T = (Rand(64, 64 * 64) + s.length() * 32) % 16 + 16;
			while (T--)
			{
				int n = (s.length() * 32 + Rand(64, 64 * 64)) % 32 + 32;
				ofile << "// ";
				for (int i = 1; i <= n; i++)
					ofile << Hashcode[Rand(64, 64 * 64) % Hashcode.length()];
				ofile << "\n";
			}
		}
		cout << "Hashed line " << cnt << endl;
		cnt++;
	}

	ifile.close();
	ofile.close();
	return 0;
}