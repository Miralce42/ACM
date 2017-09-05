//UVa-439
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>

using namespace std;

bool inside(int x, int y);
void jump();
const int MAXN = 8 + 2;
struct Node
{
	int x, y, d;
	Node(){}
	Node(int x,int y,int d=0):x(x),y(y),d(d){}
};
int chessboard[MAXN][MAXN];
Node start, dest;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		memset(chessboard, 0, sizeof(chessboard));
		start.x = s1[0] - 'a' + 1; start.y = s1[1] - '0'; start.d = 0;//横纵都从1开始
		dest.x = s2[0] - 'a' + 1; dest.y = s2[1] - '0'; dest.d = 0;
		chessboard[start.x][start.y] = 1;
		jump();
		cout << "To get from "<<s1<<" to "<<s2<<" takes "<<dest.d<<" knight moves.\n";
	}
	return 0;
}

void jump()
{
	queue<Node> q;
	q.push(start);
	while (!q.empty())
	{
		Node horse = q.front(); q.pop();
		for (int dr = -2; dr <= 2; dr++)
		{
			for (int dc = -2; dc <= 2; dc++)
			{
				int x = horse.x + dr; int y = horse.y + dc;
				if ( inside(x, y) && (abs(dr) + abs(dc)) == 3 && !chessboard[x][y])
				{
					if (dest.x == x && dest.y == y)
					{
						dest.d = horse.d + 1;
						return;
					}
					chessboard[x][y] = 1;
					q.push(Node(x, y , horse.d +1));
				}
			}
		}
	}
}

bool inside(int x, int y)
{
	return x > 0 && x < 9 && y > 0 && y < 9;
}
