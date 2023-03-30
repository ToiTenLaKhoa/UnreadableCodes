#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
string Hashcode = "";
string s;

#define rand rd
long long Rand(long long l, long long h)
{
	assert(l <= h);
	return abs(l + rd() * 1LL * rd() % (h - l + 1));
}

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

void msg(string msg)
{
	cout << msg << endl;
}

void die(string message)
{
	msg(message);
	system("pause");
	exit(0);
}

bool hashcheck()
{
	if (Hashcode.length() < 56)
		return 0;
	return 1;
}

void ps(int secs)
{
	Sleep(secs * 1000);
}

void cs()
{
	system("cls");
}

void cppexe(string name)
{
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
}

int main()
{
	cout << "Loading HASH..." << endl;
	ifstream hashin("HASH");
	ps(1);
	cs();
	if (hashin.fail())
		die("HASH not found.");
	getline(hashin, Hashcode);
	cout << "Checking Hashcode..." << endl;
	ps(1);
	cs();
	if (!hashcheck())
		die("Invalid HASH.");
	string name;
	bool valid = 0;
	while (!valid)
	{
		valid = 1;
		cout << "Enter your file name > ";
		cin >> name;
		if (ren(name, "old_" + name))
		{
			msg("File unreadable");
			valid = 0;
		}
	}
	cs();
	cppexe(name);
	return 0;
}