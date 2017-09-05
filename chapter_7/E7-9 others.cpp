#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<iostream>  
#include<queue>  
using namespace std;
const int maxn = 150, maxs = 20;
const int dx[] = { -1,1,0,0,0 };//5种移动方式
const int dy[] = { 0,0,1,-1,0 };
inline int ID(int a, int b, int c)
{
	return (a << 16) | (b << 8) | c;
}
int s[3], t[3]; //保存初末状态  
int deg[maxn];//某个格子有多少个相连的格子   
int G[maxn][5];//保存某个格子可以用到哪些格子  
inline bool conflict(int a, int b, int a2, int b2)//a,b是鬼所在的位置，因为地图使用的是一维数组表示的
{
	return a2 == b2 || (a2 == b&&b2 == a); //如果两个鬼移动到同一个位置或者位置互换则冲突  
}
int d[maxn][maxn][maxn]; //走到某个状态经过的步数，使用3维数组是因为最多3个鬼
int bfs()
{
	queue<int> q;
	memset(d, -1, sizeof(d));
	q.push(ID(s[0], s[1], s[2])); //每个状态给他编号来判断是否访问过  
	d[s[0]][s[1]][s[2]] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();//从对列中取出元素
		int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;//获取abc
		//   cout<<a<<"   "<<b<<"    "<<c<<endl;  
		if (a == t[0] && b == t[1] && c == t[2])return d[a][b][c];//到达终点
		for (int i = 0; i<deg[a]; i++) {//迭代a能移动的位置
			int a2 = G[a][i];			//获取a移动的下个位置
			for (int j = 0; j<deg[b]; j++) {//迭代b能移动的位置
				int b2 = G[b][j];			//获取b移动的下个位置
				if (conflict(a, b, a2, b2))continue;  //如果冲突：a,b移动到同一个位置  或者  a,b交换位置
				for (int k = 0; k<deg[c]; k++) {//迭代c能移动的位置
					int c2 = G[c][k];			//获取c移动的下个位置
					if (conflict(a, c, a2, c2))continue;//c和a,b是否冲突
					if (conflict(b, c, b2, c2))continue;
					if (d[a2][b2][c2] != -1)continue;	//已经走过
					d[a2][b2][c2] = d[a][b][c] + 1;		//步数加一
					q.push(ID(a2, b2, c2));				//压入栈中
				}
			}
		}
	}
	return -1;
}
int main()
{
	int w, h, n;
	//freopen("f.txt","r",stdin);  
	while (scanf("%d%d%d\n", &w, &h, &n) == 3 && n) {
		char maze[20][20];
		for (int i = 0; i<h; i++)//先用一个二维数组存储迷宫
			fgets(maze[i], 20, stdin);
		/*-----将二维的地图一维化------*/
		int cnt, x[maxn], y[maxn], id[maxn][maxn];//cnt:非过道个数；x，y数组用来存储第cnt个过道的x,y值；
		cnt = 0;					//id是来存储过道某个对应的cnt值
		for (int i = 0; i<h; i++) {
			for (int j = 0; j<w; j++) {
				if (maze[i][j] != '#') {  //把障碍去掉，建图  
					x[cnt] = i, y[cnt] = j, id[i][j] = cnt;
					if (islower(maze[i][j]))s[maze[i][j] - 'a'] = cnt;
					else if (isupper(maze[i][j]))t[maze[i][j] - 'A'] = cnt;
					cnt++;
				}
			}
		}
		for (int i = 0; i<cnt; i++) {
			deg[i] = 0;//deg用来存储每个过道连接的过道个数
			for (int dir = 0; dir<5; dir++) {
				int nx = x[i] + dx[dir], ny = y[i] + dy[dir];//确定5个移动方式的新x,y
				if (maze[nx][ny] != '#')G[i][deg[i]++] = id[nx][ny];//统计出每个位置所有可以移动到的位置  
			}
		}
		//n==1||n==2时，把格子加上，凑够三个，初末位置重合  
		if (n <= 2) {
			deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt++;
		}
		if (n <= 1) {
			deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt++;
		}
		printf("%d\n", bfs());

	}
}
