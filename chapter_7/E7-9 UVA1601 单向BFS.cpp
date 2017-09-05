//UVA1601 ����7-9 AC ����BFS 
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

int s[3], t[3];//�����ĩ״̬  
int deg[MAXN], G[MAXN][5];//deg:ĳ�������ж��ٸ������ĸ��� ,G:��ĳ�����ӿ����õ���Щ����  
int d[MAXN][MAXN][MAXN];	//�ߵ�ĳ��״̬�����Ĳ���

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int w, h, n;
	while (scanf("%d %d %d", &w, &h, &n) && n) {
		getchar();
		char maze[MAXS][MAXS];
		for (int i = 0; i < h; i++) 
			fgets(maze[i], 20, stdin);//��˵ֱ��scanf�ᳬʱ
		//Ϊ֮��ת��Ϊһά������׼��
		int cnt = 0, x[MAXN], y[MAXN], id[MAXN][MAXN];//cnt:�ǹ���������x��y���������洢��cnt��������x,yֵ��
		for (int i = 0; i < h; i++) {				//id�����洢����ĳ����Ӧ��cntֵ
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
		//��ʼ��deg,G��deg:ÿ������5���ƶ���ʽ����֮���ڵĹ�������
		for (int i = 0; i < cnt; i++) {
			deg[i] = 0;
			for (int dir = 0; dir < 5; dir++) {
				int newx = x[i] + dx[dir];	int newy = y[i] + dy[dir];
				if (maze[newx][newy] != '#') G[i][deg[i]++] = id[newx][newy];
			}
		}
		//�����ĸ�������3��������������������BFS�н��ж�ÿ��������ж����Ӷ�����Ҫ��̬����
		//������deg��G�п���һ����������Ÿ���ӵĹ��ʼĩλ�á�
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
	q.push(encoding(s[0], s[1], s[2]));//���б��룬�Ž�ջ�� 
	while (q.size()) {
		int x = q.front(); q.pop();
		int a = (x >> 16) & 0xff, b = (x >> 8) & 0xff, c = x & 0xff;//��ȡabc
		if (a == t[0] && b == t[1] && c == t[2]) return d[a][b][c];//�����յ�
		for (int i = 0; i < deg[a]; i++) {//a���ƶ���λ��
			int na = G[a][i];
			for (int j = 0; j < deg[b]; j++) {
				int nb = G[b][j];
				if (conflict(a, b, na, nb)) continue;//�����ͻ��a,b�ƶ���ͬһ��λ��  ����  a,b����λ��
				for (int k = 0; k < deg[c]; k++) {
					int nc = G[c][k];
					if (conflict(a, c, na, nc))continue;
					if (conflict(b, c, nb, nc))continue;
					if (d[na][nb][nc] != -1)continue;//d��ֵ˵����״̬�Ѿ����ʹ�
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
