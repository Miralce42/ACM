//UVa6-6-AC-P177-ĞŞ¸ÄÌìÆ½ 
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<map>

using namespace std;

void dfs(int dep, int x, int y);

map<long long, int> sumw;
string s;
int sum, cur;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	while (n--)
	{
		int maxn = 0;;
		sumw.clear();sum = 0;
		cin >> s;
		dfs(0, 0, s.length() - 1);
		for (map<long long, int>::iterator it = sumw.begin(); it != sumw.end(); it++)
			maxn =it->second > maxn ? it->second : maxn;
		cout << sum - maxn << endl;
	}
	return 0;
}

void dfs(int dep,int x ,int y)
{
	if (s[x] == '[') {
		int p = 0;
		for (int i = x + 1; i != y; ++i) {
			if (s[i] == '[') ++p;
			if (s[i] == ']') --p;
			if (p == 0 && s[i] == ',') {
				dfs(dep + 1, x + 1, i - 1);
				dfs(dep + 1, i + 1, y - 1);
			}
		}
	}
	else {
		long long w = 0;
		for (int i = x; i <= y; ++i) w = w * 10 + s[i] - '0';
		++sum, ++sumw[w << dep];
	}
}
