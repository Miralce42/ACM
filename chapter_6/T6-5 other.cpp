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
bool vis[MAXN][MAXN][MAXN];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int n, rows, cols, res;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n;
	int line = 1;
	while (n--)
	{
		memset(vis,0,sizeof(vis));
		cin >> rows >> cols;
		line++;
		cin >> res;
		line++;
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= cols; j++)
				cin >> grid[i][j];
			line++;
		}
		cout << move()<<endl;
	}
	return 0;
}

int move()
{
	if(rows == 1 && cols == 1) return 0;
	queue<Node> q;
	q.push(Node(1,1,0,0));
	vis[1][1][0]=true;
	while (!q.empty())
	{
		Node rob = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int r = rob.r + dr[i];
			int c = rob.c + dc[i];
			int layer = rob.s;
			if (r == rows && c == cols) return rob.d + 1;
			if(grid[r][c])  layer++;
            else  layer=0;
			if(layer<=res&&!vis[r][c][layer]&&inside(r,c))
            {
                vis[r][c][layer]=true;
                q.push(Node(r,c,rob.d+1,layer));
            }
		}
	}
	return -1;
}

bool inside(int r, int c)
{
	return r > 0 && r <= rows  && c > 0 && c <= cols;
}
