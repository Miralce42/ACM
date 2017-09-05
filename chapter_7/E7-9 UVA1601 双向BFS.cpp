//UVA1601 例题7-9 AC 双向BFS 
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
int vis[MAXN][MAXN][MAXN];	//标记是否走过0：都未经过，1：正向经过；2：逆向经过 

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
	int cnt;
	queue<int> qs; queue<int> qt;
	memset(d, -1, sizeof(d));memset(vis, 0, sizeof(vis));//初始化距离数组 和记录访问状况的数组 
	d[s[0]][s[1]][s[2]] = 0;d[t[0]][t[1]][t[2]] = 1; 
	vis[s[0]][s[1]][s[2]] = 1;vis[t[0]][t[1]][t[2]] = 2;
	qs.push(encoding(s[0], s[1], s[2]));qt.push(encoding(t[0], t[1], t[2]));
	while (qs.size() || qt.size()) {
		cnt = qs.size();	//每当访问一层之后再交替，这里记录每层的结点个数 
		while(cnt--){
			int x = qs.front(); qs.pop();
			int a = (x >> 16) & 0xff, b = (x >> 8) & 0xff, c = x & 0xff;//解码，获取abc 
			for (int i = 0; i < deg[a]; i++) {
				int na = G[a][i];
				for (int j = 0; j < deg[b]; j++) {
					int nb = G[b][j];
					if (conflict(a, b, na, nb)) continue;
					for (int k = 0; k < deg[c]; k++) {
						int nc = G[c][k];
						if (conflict(a, c, na, nc))continue;
						if (conflict(b, c, nb, nc))continue;
						if (vis[na][nb][nc] == 1)continue;		//正向已经走过则跳过 
						if (vis[na][nb][nc] == 2)	return d[a][b][c] + d[na][nb][nc];//反向走过，说明找到出口，返回正反步数之和 
						d[na][nb][nc] = d[a][b][c] + 1; 	//增加步数 
						vis[na][nb][nc] = 1;			//记录访问 
						qs.push(encoding(na, nb, nc));
					}
				}
			}
		}
		cnt = qt.size();
		while (cnt--) {
			int x = qt.front(); qt.pop();
			int a = (x >> 16) & 0xff, b = (x >> 8) & 0xff, c = x & 0xff;
			if (a == s[0] && b == s[1] && c == s[2]) return d[a][b][c] + d[a][b][c];
			for (int i = 0; i < deg[a]; i++) {
				int na = G[a][i];
				for (int j = 0; j < deg[b]; j++) {
					int nb = G[b][j];
					if (conflict(a, b, na, nb)) continue;
					for (int k = 0; k < deg[c]; k++) {
						int nc = G[c][k];
						if (conflict(a, c, na, nc))continue;
						if (conflict(b, c, nb, nc))continue;
						if (vis[na][nb][nc] == 2)continue;
						if (vis[na][nb][nc] == 1)	return d[a][b][c] + d[na][nb][nc];
						d[na][nb][nc] = d[a][b][c] + 1;
						vis[na][nb][nc] = 2;
						qt.push(encoding(na, nb, nc));
					}
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
