
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>

using namespace std;

bool inside(int x, int y);
int move();
const int MAXN = 20 + 10;

struct Node
{
	int r, c, d, s;
	Node() {}
	Node(int x, int y, int d = 0 ,int s = 0) :r(x), c(y), d(d), s(s) {}
};

int grid[MAXN][MAXN];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int n, rows, cols, res;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> n;
	while (n--)
	{
		cin >> rows >> cols;
		cin >> res;
		for (int i = 1; i <= rows; i++)
			for (int j = 1; j <= cols; j++)
				cin >> grid[i][j];
		cout << move() << endl;
	}
	return 0;
}

int move()
{
	queue<Node> q;
	q.push(Node(1,1,0,res));
	grid[1][1] = -1;
	while (!q.empty())
	{
		Node rob = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int r = rob.r + dr[i];
			int c = rob.c + dc[i];
			if (r == rows && c == cols) return rob.d + 1;
			if (inside(r, c) && grid[r][c] != -1)
			{
				if (grid[r][c] == 1 && rob.s < 1)
					continue;
				else if (grid[r][c] == 1)
					q.push(Node(r, c, rob.d + 1, rob.s - 1));
				else
				{
					q.push(Node(r, c, rob.d + 1, res));
				}
				grid[r][c] = -1;
			}
		}
	}
	return -1;
}

bool inside(int r, int c)
{
	return r > 0 && r <= rows  && c > 0 && c <= cols;
}
