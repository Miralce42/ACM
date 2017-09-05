//UVa1152 map TLE 
#include<iostream>
#include<map>
#include<cstring> 

using namespace std;

const int MAXN = 4000 + 100;

map<int,int> mp;
int num[4][MAXN];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n, m;
	cin >> n;
	while (n--) {
		int cnt = 0;
		cin >> m;
		mp.clear();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < 4; j++)
				cin >> num[j][i];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				mp[num[0][i] + num[1][j]]++;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				if (mp[-num[2][i] - num[3][j]] > 0) 
					cnt += mp[-num[2][i] - num[3][j]];
		cout <<cnt << endl;
		if (n != 0) cout << endl;
	}
	return 0;
}
