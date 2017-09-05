//UVA1601 例题7-9 AC 单向BFS 
#include<cstdio>
#include<queue>
#include<iostream>  
#include<cstring>

using namespace std;

int bfs();
bool conflict(int a, int b, int na, int nb);
int encoding(int a, int b, int c);

const int MAXN = 150;
const int MAXS = 20;
const int dx[] = { 1,-1,0,0,0 };
const int dy[] = { 0,0,1,-1,0 };

int s[3], t[3];//保存初末状态  
int deg[MAXN], G[MAXN][5];//deg:某个格子有多少个相连的格子 ,G:存某个格子可以用到哪些格子  
int d[MAXN][MAXN][MAXN];	//走到某个状态经过的步数

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int w, h, n;
	while (scanf("%d %d %d", &w, &h, &n) && n) {
		getchar();
		char maze[MAXS][MAXS];
		for (int i = 0; i < h; i++) 
			fgets(maze[i], 20, stdin);//听说直接scanf会超时
		//为之后转化为一维数组做准备
		int cnt = 0, x[MAXN], y[MAXN], id[MAXN][MAXN];//cnt:非过道个数；x，y数组用来存储第cnt个过道的x,y值；
		for (int i = 0; i < h; i++) {				//id是来存储过道某个对应的cnt值
			for (int j = 0; j < w; j++) {
				if (maze[i][j] != '#') {
					if (islower(maze[i][j]))
						s[maze[i][j] - 'a'] = cnt;
					if (isupper(maze[i][j])) 
						t[maze[i][j] - 'A'] = cnt;
					x[cnt] = i; y[cnt] = j; id[i][j] = cnt++;
 				}
			}
		}
		//初始化deg,G。deg:每个过道5个移动方式上与之相邻的过道个数
		for (int i = 0; i < cnt; i++) {
			deg[i] = 0;
			for (int dir = 0; dir < 5; dir++) {
				int newx = x[i] + dx[dir];	int newy = y[i] + dy[dir];
				if (maze[newx][newy] != '#') G[i][deg[i]++] = id[newx][newy];
			}
		}
		//如果鬼的个数不足3个，补成三个，方便在BFS中进行对每个鬼进行行动，从而不需要动态考虑
		//并且在deg和G中开辟一个过道来存放该添加的鬼的始末位置。
		if (n <= 2) {
			deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt++;
		}
		if (n <= 1) {
			deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt++;
		}
		printf("%d\n", bfs());
	}
	return 0;
}

int bfs()
{
	queue<int> q;
	memset(d, -1, sizeof(d));
	d[s[0]][s[1]][s[2]] = 0;
	q.push(encoding(s[0], s[1], s[2]));//进行编码，放进栈中 
	while (q.size()) {
		int x = q.front(); q.pop();
		int a = (x >> 16) & 0xff, b = (x >> 8) & 0xff, c = x & 0xff;//获取abc
		if (a == t[0] && b == t[1] && c == t[2]) return d[a][b][c];//到达终点
		for (int i = 0; i < deg[a]; i++) {//a能移动的位置
			int na = G[a][i];
			for (int j = 0; j < deg[b]; j++) {
				int nb = G[b][j];
				if (conflict(a, b, na, nb)) continue;//如果冲突：a,b移动到同一个位置  或者  a,b交换位置
				for (int k = 0; k < deg[c]; k++) {
					int nc = G[c][k];
					if (conflict(a, c, na, nc))continue;
					if (conflict(b, c, nb, nc))continue;
					if (d[na][nb][nc] != -1)continue;//d有值说明该状态已经访问过
					d[na][nb][nc] = d[a][b][c] + 1;
					q.push(encoding(na, nb, nc));
				}
			}
		}
	}
}

bool conflict(int a, int b, int na, int nb)
{
	return (na == nb) || (na == b && nb == a);
}

int encoding(int a, int b, int c)
{
	return a << 16 | b << 8 | c;
}
