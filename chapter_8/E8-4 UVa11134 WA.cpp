//E8-4 Uva11134 WA
//思路（正确性未知）：由于题目中x和y之间互相不影响，所以x和y可以独立操作
//将棋盘上统计x轴每个位置上可以放多少个棋子，然后每次寻找位置时都找位置上能放棋子最少的
//看看所有棋子是否都能归位，y轴作同样处理 
#include<iostream>
#include<cstring>

using namespace std;

int find_min(int n,int *x, int l, int r);
void count(int n);
void stat(int i, int op);

const int MAXN = 5000 + 10;
const int INF = 0x7fffffff;

int arr[4][MAXN];
int maze_x[MAXN], maze_y[MAXN], rook_x[MAXN], rook_y[MAXN];

int main()
{
	int n;
	while (cin >> n && n) { 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 4; j++)
				cin >> arr[j][i];
		count(n);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			int x = find_min(n,maze_x, arr[0][i], arr[2][i]);
			int y = find_min(n,maze_y, arr[1][i], arr[3][i]);
			if (!x || !y) {
				ok = false; break;
			}
			stat(i, -1);			//每次选择一个马之后要将对他的统计减去 
			rook_x[i] = x; maze_x[x] = INF;
			rook_y[i] = y; maze_y[y] = INF;
		}
		if (ok)
			for (int i = 0; i < n; i++)
				cout << rook_x[i] << " " << rook_y[i] << endl;
		else
			cout << "IMPOSSIBLE \n";
	}
	return 0;
}

int find_min(int n,int *x, int l, int r)//找到当前马的个数最少的位置 
{
	int min = x[l], idx = l;
	for (int i = l+1; i <= r; i++) {
		if(x[i] < min){
			min = x[i];
			idx = i;
		}
	}
	if (min > n) idx = 0;//该范围内全部已被占用
	return idx;
}

void count(int n)//统计每个x(y)可以存在的马的个数 
{
	memset(maze_x, 0, sizeof(maze_x));
	memset(maze_y, 0, sizeof(maze_y));
	for (int i = 0; i < n; i++)
	{
		stat(i, 1);
	}
}

void stat(int i, int op)//统计 
{
	for (int j = arr[0][i]; j <= arr[2][i]; j++)
		maze_x[j] += op;
	for (int j = arr[1][i]; j <= arr[3][i]; j++)
		maze_y[j] += op;
}
