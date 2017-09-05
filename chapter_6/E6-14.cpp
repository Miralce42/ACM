#include<iostream>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

struct Node
{
	int x, y, dir;
	Node() {}
	Node(int x, int y, int d = -1) :x(x), y(y), dir(d) {}
};

const int MAXN = 9 + 5;
const char *dircs = "NESW";
const char *turns = "FLR";
const int dr[4] = { -1,0,1,0 };
const int dc[4] = { 0,1,0,-1 };
int d[MAXN][MAXN][4], has_edge[MAXN][MAXN][4][3];
Node p[MAXN][MAXN][4];
string name;

int dir_id(char c) { return strchr(dircs, c) - dircs; }	//返回c在dircs的下标
int turn_id(char c) { return strchr(turns, c) - turns; }
void inti(Node& begin, Node& end);
bool inside(int x, int y);
void print(Node u, Node begin);
void BFS(const Node begin, const Node end);
Node walk(const Node& u, int turn);

int main()
{
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout); 
	while (cin >> name && name != "END")
	{
		Node begin, end;
		inti(begin, end);
		BFS(begin, end);
	}
	return 0;
}

void BFS(const Node begin, const Node end)
{
	queue<Node> q;
	Node u = walk(begin, 0);
	p[u.x][u.y][u.dir] = begin;
	d[u.x][u.y][u.dir] = 0;
	q.push(u);
	while (!q.empty())
	{
		Node u = q.front(); q.pop();
		if (u.x == end.x && u.y == end.y)
		{
			print(u, begin);
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			Node v = walk(u, i);
			if (has_edge[u.x][u.y][u.dir][i] && inside(v.x, v.y) && d[v.x][v.y][v.dir] < 0)
			{
				d[v.x][v.y][v.dir] = d[u.x][u.y][u.dir] + 1;
				p[v.x][v.y][v.dir] = u;
				q.push(v);
			}
		}
	}
	cout << name << endl << "  No Solution Possible\n";
}

void print(Node u, Node begin)
{
	vector<Node> v;
	while (1)
	{
		v.push_back(u);
		if (d[u.x][u.y][u.dir] == 0)
			break;
		u = p[u.x][u.y][u.dir];
	}
	v.push_back(begin);

	cout << name;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if ((v.size()- 1-i) % 10 == 0)
			cout << endl << " ";
		cout << " (" << v[i].x << "," << v[i].y << ")";
	}
	cout << endl;
}

bool inside(int x, int y)
{
	if (x < 1 || y < 1 || x > 9 || y > 9)
		return false;
	return true;
}

Node walk(const Node& u, int turn)
{
	int dir = u.dir;
	if (turn == 1) dir = (dir + 3) % 4;
	if (turn == 2) dir = (dir + 1) % 4;
	return Node(u.x + dr[dir], u.y + dc[dir], dir);
}

void inti(Node &begin, Node &end)
{
	int x, y;
	string s;
	cin >> x >> y >> s;
	begin = Node(x, y, dir_id(s[0]));
	cin >> x >> y;
	end.x = x; end.y = y;
	memset(has_edge, 0, sizeof(has_edge));
	memset(d, -1, sizeof(d));
	while (cin >> x && x)
	{
		cin >> y;
		while (cin >> s && s != "*")
		{
			int dir = dir_id(s[0]);
			for (int i = 1; i < s.length(); i++)
			{
				int turn = turn_id(s[i]);
				has_edge[x][y][dir][turn] = 1;
			}
		}
	}
}
