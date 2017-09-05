#include<iostream>
#include<cmath>
#include<sstream>
#include<string>
#include<cstring>

using namespace std;

const int MAXLEN = 128 + 10;

int leaf[MAXLEN];

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout); 
	int n, m, len, kase = 0;;
	string s,num;
	while (cin >> n && n)
	{
		getchar();
		cout << "S-Tree #" << ++kase << ":\n";
		memset(leaf, 0, sizeof(leaf));
		len = pow(2, n);
		getline(cin, s);
		for (int i = 0; i < len; i++)
		{
			char ch = getchar();
			leaf[i] = ch - '0';
		}
		cin >> m;
		while (m--)
		{
			int x,cur = 1;
			cin >> num;
			for (int i = 1; i < s.length(); i = i + 3)
			{
				int idx = s[i] - '1';
				x = num[idx] - '0';
				if (x == 0)
					cur = 2 * cur;
				else
					cur = 2 * cur + 1;
			}
			cout << leaf[cur - len];
		}
		cout << endl<<endl;
	}
}
