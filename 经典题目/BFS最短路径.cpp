//迷宫最优路线求解  BFS 
#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>

using namespace std;

struct Point
{
	int x, y;
	int d;
	Point() {}
	Point(int x, int y,int d = 0) :x(x), y(y),d(d) {}
	bool operator== (Point b)
	{
		return x == b.x && y == b.y;
	}
};

const int MAXN = 9;

void copy(int c[MAXN][MAXN]);
void print(int c[MAXN][MAXN]);
 
int maze[MAXN][MAXN] = {1,1,1,1,1,1,1,1,1,
						1,0,0,1,0,0,1,0,1,
						1,0,0,1,1,0,0,0,1,
						1,0,1,0,1,1,0,1,1,
						1,0,0,0,0,1,0,0,1,
						1,1,0,1,0,1,0,0,1,
						1,1,0,1,0,1,0,0,1,
						1,1,0,1,0,0,0,0,1,
						1,1,1,1,1,1,1,1,1,
						};

int main()
{
	int n, a, b, c, d;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c >> d;
		int cpy[MAXN][MAXN];
		copy(cpy);
		Point begin(a, b), end(c, d);
		queue<Point> q;
		q.push(begin);
		Point p,pt;
		bool find = false;
		while (!q.empty())
		{
			p = q.front(); q.pop();
			int d = p.d + 1;
			for (int i = p.x - 1; i <= p.x + 1; i++)
			{
				for (int j = p.y - 1; j <= p.y + 1; j++)
				{
					if (fabs(i + j - p.x - p.y) != 1) //每次只能走上下左右，斜的不能走
						continue;
					pt = Point(i, j);
					if (maze[i][j] == 0 && cpy[i][j] == 0 && !(pt == begin))
					{
						cpy[i][j] = pt.d = d;
						if (pt == end)
						{
							find = true;
							break;
						}
						q.push(pt);
					}
				}
				if (find)
					break;
			}
		}
		cout << cpy[c][d] << endl;
	}
	return 0;
}

void copy(int c[MAXN][MAXN])
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			c[i][j] = maze[i][j];
}

void print(int c[MAXN][MAXN])
{
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
}
