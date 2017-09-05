//测试结果没有错误，但是WA 
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool dfs(int row, int col);

//#define forfor  for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++)

const int MAXN = 100 + 10;

char field[MAXN][MAXN];
int oil[MAXN][MAXN];
int n, m;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while (cin >> n >> m && n)
	{
		int sum = 0;
		memset(field, 0, sizeof(field));
		memset(oil, 0, sizeof(field));
		for (int i = 0; i < n; i++)	
			for (int j = 0; j < m; j++) 
				cin >> field[i][j];
		for (int i = 0; i < n; i++)	
		{
			for (int j = 0; j < m; j++)
				{
					if (dfs(i, j))
						sum++;
				}
		}
		cout << sum << endl;
	}
	return 0;
}

//是不是发现一个新的油田
bool dfs(int row, int col)
{
	bool new_field = false;
	if (oil[row][col]) return new_field;
	else if (field[row][col] == '@')
	{
		oil[row][col] = 1;
		new_field = true;
		for (int i = row - 1; i <= row + 1; i++)
		{
			for (int j = col - 1; j <= col + 1; j++)
			{
				if (i >= 0 && i < n && j >= 0 && j < m)
				{
					dfs(i, j);
				}
			}
		}
	}
	return new_field;
}
