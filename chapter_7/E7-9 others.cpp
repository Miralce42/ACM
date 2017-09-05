#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<iostream>  
#include<queue>  
using namespace std;
const int maxn = 150, maxs = 20;
const int dx[] = { -1,1,0,0,0 };//5���ƶ���ʽ
const int dy[] = { 0,0,1,-1,0 };
inline int ID(int a, int b, int c)
{
	return (a << 16) | (b << 8) | c;
}
int s[3], t[3]; //�����ĩ״̬  
int deg[maxn];//ĳ�������ж��ٸ������ĸ���   
int G[maxn][5];//����ĳ�����ӿ����õ���Щ����  
inline bool conflict(int a, int b, int a2, int b2)//a,b�ǹ����ڵ�λ�ã���Ϊ��ͼʹ�õ���һά�����ʾ��
{
	return a2 == b2 || (a2 == b&&b2 == a); //����������ƶ���ͬһ��λ�û���λ�û������ͻ  
}
int d[maxn][maxn][maxn]; //�ߵ�ĳ��״̬�����Ĳ�����ʹ��3ά��������Ϊ���3����
int bfs()
{
	queue<int> q;
	memset(d, -1, sizeof(d));
	q.push(ID(s[0], s[1], s[2])); //ÿ��״̬����������ж��Ƿ���ʹ�  
	d[s[0]][s[1]][s[2]] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();//�Ӷ�����ȡ��Ԫ��
		int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;//��ȡabc
		//   cout<<a<<"   "<<b<<"    "<<c<<endl;  
		if (a == t[0] && b == t[1] && c == t[2])return d[a][b][c];//�����յ�
		for (int i = 0; i<deg[a]; i++) {//����a���ƶ���λ��
			int a2 = G[a][i];			//��ȡa�ƶ����¸�λ��
			for (int j = 0; j<deg[b]; j++) {//����b���ƶ���λ��
				int b2 = G[b][j];			//��ȡb�ƶ����¸�λ��
				if (conflict(a, b, a2, b2))continue;  //�����ͻ��a,b�ƶ���ͬһ��λ��  ����  a,b����λ��
				for (int k = 0; k<deg[c]; k++) {//����c���ƶ���λ��
					int c2 = G[c][k];			//��ȡc�ƶ����¸�λ��
					if (conflict(a, c, a2, c2))continue;//c��a,b�Ƿ��ͻ
					if (conflict(b, c, b2, c2))continue;
					if (d[a2][b2][c2] != -1)continue;	//�Ѿ��߹�
					d[a2][b2][c2] = d[a][b][c] + 1;		//������һ
					q.push(ID(a2, b2, c2));				//ѹ��ջ��
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
		for (int i = 0; i<h; i++)//����һ����ά����洢�Թ�
			fgets(maze[i], 20, stdin);
		/*-----����ά�ĵ�ͼһά��------*/
		int cnt, x[maxn], y[maxn], id[maxn][maxn];//cnt:�ǹ���������x��y���������洢��cnt��������x,yֵ��
		cnt = 0;					//id�����洢����ĳ����Ӧ��cntֵ
		for (int i = 0; i<h; i++) {
			for (int j = 0; j<w; j++) {
				if (maze[i][j] != '#') {  //���ϰ�ȥ������ͼ  
					x[cnt] = i, y[cnt] = j, id[i][j] = cnt;
					if (islower(maze[i][j]))s[maze[i][j] - 'a'] = cnt;
					else if (isupper(maze[i][j]))t[maze[i][j] - 'A'] = cnt;
					cnt++;
				}
			}
		}
		for (int i = 0; i<cnt; i++) {
			deg[i] = 0;//deg�����洢ÿ���������ӵĹ�������
			for (int dir = 0; dir<5; dir++) {
				int nx = x[i] + dx[dir], ny = y[i] + dy[dir];//ȷ��5���ƶ���ʽ����x,y
				if (maze[nx][ny] != '#')G[i][deg[i]++] = id[nx][ny];//ͳ�Ƴ�ÿ��λ�����п����ƶ�����λ��  
			}
		}
		//n==1||n==2ʱ���Ѹ��Ӽ��ϣ��չ���������ĩλ���غ�  
		if (n <= 2) {
			deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt++;
		}
		if (n <= 1) {
			deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt++;
		}
		printf("%d\n", bfs());

	}
}
